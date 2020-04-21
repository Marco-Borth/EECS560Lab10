/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.cpp
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 8 – Implementation of Maxmin Heap
 * Description:  Executive Class creates and runs the Operator class.
 * Date: 4/7/20
 *
 ---------------------------------------------------------------------------- */
#include "Executive.h"
#include "Operator.h"
#include <string>
using namespace std;

// Create Executive Object.
Executive::Executive(string file1name) {
	file1 = file1name;
}

void Executive::run() {
	Operator Prog(file1);
	Prog.run();
}
