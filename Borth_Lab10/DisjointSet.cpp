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
void DisjointSet<T>::Union(int p1, int p2) {
	p1--;
	p2--;
	if ((p1 >= 0 && p1 < m_size) && (p2 >= 0 && p2 < m_size) && (p1 != p2)) {
		if (m_arr[p1]->getEntry() < m_arr[p2]->getEntry()) {
			if (m_arr[p1]->getNext() == nullptr) {
				m_arr[p1]->setNext(m_arr[p2]);
				cout << "\nOutput: Union on " << m_arr[p1]->getEntry() << " and " << m_arr[p2]->getEntry() << " has been done.";
				cout << " The representative element is " << m_arr[p1]->getEntry() << ".\n\n";
			} else {
				int newp1 = 0;
				for (int i = 0; i < m_size; i++) {
					if (m_arr[i]->getEntry() == m_arr[p1]->getNext()->getEntry()) {
						newp1 = i;
					}
				}
				p1 = newp1;
				p1++;
				p2++;
				Union(p1, p2);
			}
		} else {
			p2++;
			p1++;
			Union(p2, p1);
		}
	} else {
		throw(std::runtime_error("ERROR: Invalid Indexs.\n"));
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
