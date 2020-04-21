/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.h
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 8 – Implementation of Maxmin Heap
 * Description:  Executive Class is defined.
 * Date: 4/7/20
 *
 ---------------------------------------------------------------------------- */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <stdexcept>
using namespace std;

class Executive
{
private:
	string file1;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

/*
* @pre filename is a string.
* @post Executive object is constructed.
*/
	Executive(string file1name);
};

#endif
