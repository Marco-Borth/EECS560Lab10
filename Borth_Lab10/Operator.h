/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.h
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 10 – Implementation of Disjoint Sets and Graphs
 * Description:  Operator Class is defined.
 * Date: 4/21/20
 *
 ---------------------------------------------------------------------------- */

#ifndef OPERATOR_H
#define OPERATOR_H

#include "DisjointSet.h"
#include "Heap.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

class Operator
{
private:
  int option;

  string file, graph;

  DisjointSet <int> setMaster;

  int islandNumber;
  string* Island;
  int** islandDistances;
  int* islandConnections;
  bool** connection;

  Heap<int> sumOfDistance;

  ifstream inFile;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

/**
* @pre none.
* @post prints list of commands to display for the user.
*/
  void printCommands();

  void findMinEdge(int edges, bool newEdge, int origin, int next);

  void MakeSet();

  void BuildGraph();

/*
* @pre filename is a string.
* @post Operator object is constructed, file == filename.
*/
  Operator(string file1, string file2);
};
#endif
