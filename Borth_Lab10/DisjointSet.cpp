/* -----------------------------------------------------------------------------
 *
 * File Name:  DisjointSet.cpp
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 10 – Implementation of Disjoint Sets and Graphs
 * Description:  DisjointSet methods are defined.
 * Date: 4/21/20
 *
 ---------------------------------------------------------------------------- */

template <typename T>
DisjointSet<T>::DisjointSet() {
	m_size = 1;
	m_heapSize = 0;
	m_arr = new Node<T>* [m_size];
}

template <typename T>
DisjointSet<T>::~DisjointSet() {
	clear();
	delete[] m_arr;
}

template <typename T>
bool DisjointSet<T>::isEmpty() const {
	if (m_heapSize > 0)
		return false;
	else
		return true;
}

template <typename T>
T DisjointSet<T>::getEntry(int index) {
	if (index >= 0 && index < m_size) {
		return m_arr[index]->getEntry();
	} else {
		throw(std::runtime_error("ERROR: Invalid Index.\n"));
	}
}

template <typename T>
int DisjointSet<T>::getSize() {
	return m_size;
}

template <typename T>
void DisjointSet<T>::resize() {
	Node<T>** tempArr = new Node<T>* [m_size + 1];

	for(int i = 0; i < m_size; i++) {
		tempArr[i] = m_arr[i];
	}

	Node<T>** swap = m_arr;
	m_arr = tempArr;
	tempArr = swap;

	delete[] tempArr;
	swap = nullptr;
	delete swap;
	m_size++;
}

template <typename T>
void DisjointSet<T>::add(T data) {
	if (m_heapSize == m_size) {
		resize();
		add(data);
	} else {
		Node<T>* temp = new Node<T>(data);
		m_arr[m_heapSize] = temp;
		m_heapSize++;
	}
}

template <typename T>
void DisjointSet<T>::clear() {
	if (!isEmpty()) {
		for(int i = 0; i < m_size; i++) {
			m_arr[i].~Node<T>();
		}
	}

	m_heapSize = 0;
}

template <typename T>
void DisjointSet<T>::remove(int index) {
	if (!isEmpty()) {
		int heapBound = m_size - 1;

		T temp = m_arr[heapBound];
		m_arr[heapBound] = m_arr[index];
		m_arr[index] = temp;

		delete m_arr[heapBound];

		Node<T>** tempArr = new Node<T>* [m_size];

		for(int i = 0; i < m_size - 1; i++) {
			tempArr[i] = m_arr[i];
		}

		Node<T>** swap = m_arr;
		m_arr = tempArr;
		tempArr = swap;

		delete[] tempArr;
		swap = nullptr;
		delete swap;
		m_size--;
		m_heapSize--;
	} else
		throw(std::runtime_error("ERROR: Heap is empty.\n"));
}
