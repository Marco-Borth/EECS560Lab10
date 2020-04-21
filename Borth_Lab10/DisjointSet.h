/* -----------------------------------------------------------------------------
 *
 * File Name:  DisjointSet.h
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 10 – Implementation of Disjoint Sets and Graphs
 * Description:  DisjointSet Template Class is defined.
 * Date: 4/21/20
 *
 ---------------------------------------------------------------------------- */

#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include "Node.h"
#include <math.h>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept> //For runtime_error
using namespace std;

template <typename T>
class DisjointSet
{
private:
  Node<T>** m_arr;
  int m_size, m_heapSize;

/*
* @pre add must call downHeap.
* @post increments the size of m_arr by 1 and retains its elements.
*/
  void resize();

public:
/*
* @pre define T object.
* @post MaxHeap object is constructed.
*/
  DisjointSet();

/*
* @pre none.
* @post ~MaxHeap clears all BinaryNodes and deletes m_arr.
*/
  ~DisjointSet();

  T getEntry(int index);

  int getSize();

/*
* @pre none.
* @post isEmpty returns false if m_heapSize > 0, returns true otherwise.
*/
  bool isEmpty() const;

/*
* @pre none.
* @param data is a valid T object.
* @post adds a BinaryNode to m_arr and upHeaps the BinaryNode as necessary.
* @post resizes m_arr if necessary to add BinaryNode to m_arr.
*/
  void add(T data);

  void Union(int p1, int p2);

/*
* @pre none.
* @param key is a valid K object.
* @post calls search to confirm if a BinaryNode entry == key, removes that very BinaryNode if true.
* @post if BinaryNode is not the root node, calls removeRec.
*/
  void remove(int index); //Can throw std::runtime_error

/*
* @pre none.
* @post deletes all BinaryNodes within m_arr.
*/
  void clear();
};

#include "DisjointSet.cpp"

#endif
