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

Operator::Operator(string file1){
  file = file1;
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
        // 2- DeleteMaxDownloadedGame - Complete!
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
        // 3- DeleteGame - Complete!
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
              setMaster.findElement(value);
              break;
            }
          }

        }
        // 4- PrintGamesAtMinimumLevels && 5- PrintGamesAtMaximumLevels - Complete!
        else if (option == 4) {

        }
        // 6- TotalMinimumDownloadedGames && 7- TotalMaximumDownloadedGames - Complete!
        else if (option == 5) {

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
