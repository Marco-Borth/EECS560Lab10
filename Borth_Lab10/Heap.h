/* -----------------------------------------------------------------------------
 *
 * File Name:  Heap.h
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 8 – Implementation of Maxmin Heap
 * Description:  Heap Template Class is defined as either a Min Heap or Max Heap.
 * Date: 4/7/20
 *
 ---------------------------------------------------------------------------- */

#ifndef HEAP_H
#define HEAP_H

#include <math.h>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept> //For runtime_error
using namespace std;

template <typename T>
class Heap
{
private:
  T* m_arr;
  int m_size, m_heapSize;
  int kary;
  string priority, approach;

/*
* @pre downHeap or remove must call downHeap.
* @param index is a valid int between 0 and m_size.
* @post swaps m_arr[index] with the smallest of either leftChild or rightChild BinaryNode if m_arr[leftChild] < m_arr[index] or m_arr[rightChild] < m_arr[index].
*/
  void downHeap(int index);

/*
* @pre add must call downHeap.
* @post increments the size of m_arr by 1 and retains its elements.
*/
  void resize();

  void compareFamily(int parentIndex);

  void compareExtendedFamily(int parentIndex);

public:
/*
* @pre define T object.
* @post MaxHeap object is constructed.
*/
  Heap();

/*
* @pre define T object.
* @post MaxHeap object is constructed.
*/
  Heap(int k, string mode);

/*
* @pre none.
* @post ~MaxHeap clears all BinaryNodes and deletes m_arr.
*/
  ~Heap();

  void setKary(int k);

  void setPriority(string mode);

  void setApproach(string method);

  T getEntry(int index);

  int getSize();

/*
* @pre none.
* @post isEmpty returns false if m_heapSize > 0, returns true otherwise.
*/
  bool isEmpty() const;

/*
* @pre none.
* @post getNumberOfNodes returns m_heapSize.
*/
  int getNumberOfNodes() const;

/*
* @pre none.
* @post getHeight returns the number of levels of MaxHeap.
*/
  int getHeight() const;

  int getNodeDepth(int index) const;

/*
* @pre none.
* @post peekTop returns m_arr[0].
*/
  T peekTop() const; //Can throw std::runtime_error

/*
* @pre none.
* @param data is a valid T object.
* @post adds a BinaryNode to m_arr and upHeaps the BinaryNode as necessary.
* @post resizes m_arr if necessary to add BinaryNode to m_arr.
*/
  void add(T data);

  void bottomUpHeapify();

/*
* @pre none.
* @param key is a valid K object.
* @post calls search to confirm if a BinaryNode entry == key, removes that very BinaryNode if true.
* @post if BinaryNode is not the root node, calls removeRec.
*/
  void remove(int index); //Can throw std::runtime_error

  void removeTopDown();

/*
* @pre none.
* @post deletes all BinaryNodes within m_arr.
*/
  void clear();
};

#include "Heap.cpp"

#endif
