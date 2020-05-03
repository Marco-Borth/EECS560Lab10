/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.cpp
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 10 – Implementation of Disjoint Sets and Graphs
 * Description:  Operator Class will run the Interactive program for a Disjoint Set and Graph.
 * Date: 4/21/20
 *
 ---------------------------------------------------------------------------- */

#include "Operator.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

Operator::Operator(string file1, string file2){
  sumOfDistance.setPriority("min");
  sumOfDistance.setApproach("bottomup");
  file = file1;
  graph = file2;
  BuildGraph();
}

void Operator::printCommands() {
  cout << "Please choose one of the following commands:\n\n";
  cout << "1-  MakeSet\n";
  cout << "2-  Union\n";
  cout << "3-  Find\n";
  cout << "4-  PathCompression\n";
  cout << "5-  PrintPath\n";
  cout << "6-  BFS\n";
  cout << "7-  DFS\n";
  cout << "8-  Kruskal MST\n";
  cout << "9-  Prim MST\n";
  cout << "10- Exit\n\n> ";
  cout << "Enter your choice: ";
}

void Operator::run() {
  cout << "\nWelcome to the Interactive Disjoint Sets and Graphs Program!\n\n";

  do {
    printCommands();
    cin >> option;

    while(1) {
      // Error Handling for an non-number entry.
      if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nERROR! Invalid Option!\n\n"; //if not an int, must try again.
        printCommands();
        cin >> option;
      }
      // Operation Number has been selected.
      else {
        // 1- AddGame - Complete!
        if (option == 1) {
          MakeSet();
        }
        // 2- Union - Complete!
        else if (option == 2) {
          int index1, index2;
          cout << "\n>Output: Enter the representative elements for the two sets which you wish to union:\n>";
          cin >> index1;
          cout << ">";
          cin >> index2;

          while(1) {
            if (cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
              cout << "\n>Output: Enter the representative elements for the two sets which you wish to union:\n>";
              cin >> index1;
              cout << ">";
              cin >> index2;
            } else {
              try {
                setMaster.Union(index1,index2);
              } catch (runtime_error) {
                cout << "\nERROR! Invalid Union!\n\n";
              }

              break;
            }
          }
        }
        // 3- Find - Complete!
        else if (option == 3) {
          int value;
          cout << "\n>Output: Enter the element you want to find:\n>";
          cin >> value;

          while(1){
            if (cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
              cout << "\n>Output: Enter the element you want to find:\n>";
              cin >> value;
            } else {
              try {
                setMaster.findElement(value);
              } catch (runtime_error) {
                cout << "\nERROR! Invalid Value!\n\n";
              }
              break;
            }
          }
        }
        // 4- PathCompression - Complete!
        else if (option == 4) {
          int value;
          cout << "\n>Output: Enter the element on whose set you would want to perform path compression:\n>";
          cin >> value;

          while(1){
            if (cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
              cout << "\n>Output: Enter the element on whose set you would want to perform path compression:\n>";
              cin >> value;
            } else {
              try {
                setMaster.pathCompression(value);
              } catch (runtime_error) {
                cout << "\nERROR! Invalid Value!\n\n";
              }
              break;
            }
          }
        }
        // 5- PrintPath - Complete!
        else if (option == 5) {
          int value;
          cout << "\n>Output: Enter the element you want to find the path for:\n>";
          cin >> value;

          while(1){
            if (cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
              cout << "\n>Output: Enter the element you want to find the path for:\n>";
              cin >> value;
            } else {
              try {
                setMaster.printPath(value);
              } catch (runtime_error) {
                cout << "\nERROR! Invalid Value!\n\n";
              }
              break;
            }
          }
        }
        // 6- BFS - Complete!
        else if (option == 6) {
          for (int i = 0; i < islandNumber; i++) {
            for (int j = 0; j < islandNumber; j++) {
              connection[i][j] = false;
            }
          }

          cout << "\nTree Edges: ";
          for (int j = 0; j < islandNumber; j++) {
            if (islandDistances[0][j] != -1 && islandDistances[0][j] != 1) {
              if (connection[0][j] == false && connection[j][0] == false) {
                cout << "(";
                cout << Island[0] << " " << Island[j];
                connection[0][j] = true;
                connection[j][0] = true;
                cout << ") ";
              }
            }
          }

          cout << "\nCross Edges: ";
          for (int i = 1; i < islandNumber; i++) {
            for (int j = 1; j < islandNumber; j++) {
              if (islandDistances[i][j] != -1 && islandDistances[i][j] != 1) {
                if (connection[i][j] == false && connection[j][i] == false) {
                  cout << "(";
                  cout << Island[i] << " " << Island[j];
                  connection[i][j] = true;
                  connection[j][i] = true;
                  cout << ") ";
                }
              }
            }
          }
          cout << "\n\n";
        }
        // 7- DFS - Complete!
        else if (option == 7) {
          for (int i = 0; i < islandNumber; i++) {
            for (int j = 0; j < islandNumber; j++) {
              connection[i][j] = false;
            }
          }

          cout << "\nTree Edges: ";
          for (int j = 0; j < islandNumber - 1; j++) {
            if (islandDistances[j][j + 1] != -1 && islandDistances[j][j + 1] != 1) {
              cout << "(";
              cout << Island[j] << " " << Island[j + 1];
              connection[j][j + 1] = true;
              connection[j + 1][j] = true;
              cout << ") ";
            }
          }

          cout << "\nBack Edges: ";
          for (int j = 0; j < islandNumber; j++) {
            if (islandDistances[0][j] != -1 && islandDistances[0][j] != 1) {
              if (connection[0][j] == false && connection[j][0] == false) {
                cout << "(";
                cout << Island[0] << " " << Island[j];
                connection[0][j] = true;
                connection[j][0] = true;
                cout << ") ";
              }
            }
          }

          cout << "\n\n";
        }
        // 8- Kruskal MST - Complete!
        else if (option == 8) {
          sumOfDistance.clear();
          for (int i = 0; i < islandNumber; i++) {
            for (int j = 0; j < islandNumber; j++) {
              connection[i][j] = false;
            }
          }

          findMinEdge(0, true, 0, 0);
          int totalDistance = 0;
          for (int i = 0; i < sumOfDistance.getSize(); i++) {
            totalDistance = totalDistance + sumOfDistance.getEntry(i);
          }
          cout << "\nTotal length of the route = " << totalDistance << " miles";
          cout << "\nTotal estimate to construct the bridges in the route = " << totalDistance;
          cout << " * 250K = " << totalDistance * 250 << "K $";
          cout << "\n\n";
        }
        // 9- Prim MST - Complete!
        else if (option == 9) {
          sumOfDistance.clear();
          for (int i = 0; i < islandNumber; i++) {
            for (int j = 0; j < islandNumber; j++) {
              connection[i][j] = false;
            }
          }

          findMinEdge(0, true, 0, 0);
          int totalDistance = 0;
          for (int i = 0; i < sumOfDistance.getSize(); i++) {
            totalDistance = totalDistance + sumOfDistance.getEntry(i);
          }
          cout << "\nTotal length of the route = " << totalDistance << " miles";
          cout << "\nTotal estimate to construct the bridges in the route = " << totalDistance;
          cout << " * 250K = " << totalDistance * 250 << "K $";
          cout << "\n\n";
        }
        // 10- Exit - Complete!
        else if (option == 10) {
          cout << "\nClosing Program...\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while(option != 10);

  cout << "\nBye Bye!\n";
  cout << "\nHave a nice day!...\n\n";
}

void Operator::findMinEdge(int edges, bool newEdge, int origin, int next) {
  int shortestDistance = 2147483647;
  int originIsland = 0;
  int nextIsland = 0;

  for (int i = 0; i < islandNumber; i++) {
    for (int j = 0; j < islandNumber; j++) {
      if (islandDistances[i][j] > 1 && islandDistances[i][j] < shortestDistance) {
        if (connection[i][j] == false && connection[j][i] == false) {
          shortestDistance = islandDistances[i][j];
          originIsland = i;
          nextIsland = j;
        }
      }
    }
  }

  connection[originIsland][nextIsland] = true;
  connection[nextIsland][originIsland] = true;

  if (newEdge == true) {
    cout << "(";
    cout << Island[originIsland] << " " << Island[nextIsland];
    cout << "){" << shortestDistance;
    cout << "} ";
    sumOfDistance.add(shortestDistance);
    edges++;
    newEdge = false;
    origin = originIsland;
    next = nextIsland;
  } else {
    if (nextIsland != origin) {
      cout << "(";
      cout << Island[originIsland] << " " << Island[nextIsland];
      cout << "){" << shortestDistance;
      cout << "} ";
      sumOfDistance.add(shortestDistance);
      connection[origin][nextIsland] = true;
      connection[nextIsland][origin] = true;
      edges++;
    } else {
      newEdge = true;
    }
  }

  if (edges < islandNumber - 1) {
    findMinEdge(edges, newEdge, origin, next);
  }
}

void Operator::MakeSet() {
  setMaster.clear();
  //Open File.
  inFile.open(file);

  if (!inFile.is_open()) {
    cout << "File name not valid!\n\n";
  } else {
    int RatingInputFailures = 0;
    int input;
    while (!inFile.eof()) {
      inFile >> input;

      if(inFile.fail()) {
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');
        RatingInputFailures++;
      } else {
        setMaster.add(input);
      }
    }

    if(RatingInputFailures > 1)
      cout << "ERROR! Invalid Input for Movie Ratings Detected: " << RatingInputFailures << "\n";
  }

  // Close File.
  inFile.close();
  cout << "\nOutput: The disjoint sets have been constructed.\n\n";
}


void Operator::BuildGraph() {
  delete[] Island;
  Island = new string[100];
  islandNumber = 0;
  //Open File.
  inFile.open(graph);

  if (!inFile.is_open()) {
    cout << "File name not valid!\n\n";
  } else {
    int RatingInputFailures = 0;
    string input;
    int distance;
    while (!inFile.eof()) {
      inFile >> input;
      //cout << input << "\n";

      if (inFile.fail()) {
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');
        RatingInputFailures++;
      } else {
        string name = "\0";
        name = name + input;
        if (input.at(0) != 'n' && input.at(1) != ',') {
          while (input.at(input.length() - 1) != ',') {
            inFile >> input;
            name = name + input;
          }
          Island[islandNumber] = name;
          //cout << Island[islandNumber] << "\n";

          int number;
          inFile >> number;
          islandNumber = number;
        } else {
          string size = "\0";
          for (int i = 2; i < input.length(); i++) {
            size = size + input.at(i);
          }

          int gridSize = stoi(size);
          islandDistances = new int*[gridSize];
          islandConnections = new int[gridSize];
          connection = new bool*[gridSize];

          for (int i = 0; i < gridSize; i++) {
            islandDistances[i] = new int[gridSize];
            islandConnections[i] = 0;
            connection[i] = new bool[gridSize];
          }

          for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
              inFile >> distance;
              //cout << distance << "\n";
              islandDistances[i][j] = distance;
              connection[i][j] = false;
            }
          }

          islandNumber = gridSize;
        }
      }
    }

    if(RatingInputFailures > 1)
      cout << "ERROR! Invalid Input for Movie Ratings Detected: " << RatingInputFailures << "\n";
  }

  // Close File.
  inFile.close();
  //cout << "\nOutput: The Graph have been constructed.\n\n";
}
