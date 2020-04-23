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
	if (p1 != p2) {
		int p1Index = -1;
		int p2Index = -1;
		for (int i = 0; i < m_size; i++) {
			if (m_arr[i]->getEntry() == p1) {
				p1Index = i;
			}
		}


		for (int i = 0; i < m_size; i++) {
			if (m_arr[i]->getEntry() == p2) {
				p2Index = i;
			}
		}

		if (p1Index != -1 && p2Index != -1) {
			if (m_arr[p1Index]->getEntry() < m_arr[p2Index]->getEntry()) {
				if (m_arr[p1Index]->getNext() == nullptr) {
					m_arr[p1Index]->setNext(m_arr[p2Index]);
					cout << "\nOutput: Union on " << m_arr[p1Index]->getEntry() << " and " << m_arr[p2Index]->getEntry() << " has been done.";
					int pRep = p1Index;
					for (int i = 0; i < m_size; i++) {
						if (m_arr[i]->getNext() != nullptr && m_arr[i]->getNext()->getEntry() == m_arr[pRep]->getEntry()) {
							pRep = i;
							i = 0;
						}
					}
					cout << " The representative element is " << m_arr[pRep]->getEntry() << ".\n\n";
				} else {
					int newp1 = 0;
					for (int i = 0; i < m_size; i++) {
						if (m_arr[i]->getEntry() == m_arr[p1Index]->getNext()->getEntry()) {
							newp1 = i;
						}
					}
					p1 = m_arr[newp1]->getEntry();
					Union(p1, p2);
				}
			} else {
				Union(p2, p1);
			}
		} else {
			throw(std::runtime_error("ERROR: Invalid Indexes.\n"));
		}
	} else {
		throw(std::runtime_error("ERROR: Invalid Values.\n"));
	}
}

template <typename T>
void DisjointSet<T>::findElement(int value) {
	bool isFound = false;
	int index = 0;

	for (int i = 0; i < m_size; i++) {
		if (m_arr[i]->getEntry() == value) {
			index = i;
			isFound = true;
		}
	}

	if (isFound) {
		cout << ">Output: Element " << value << " has been found successfully.";
		cout << " The representative element is " << findRepresentaive(index) << ".\n\n";
	} else {
		cout << ">Output: Sorry! " << value << " is not found!\n\n";
	}
}


template <typename T>
T DisjointSet<T>::findRepresentaive(int index) {
	if (m_arr[index]->getNext() != nullptr) {
		int repIndex = 0;
		for (int i = 0; i < m_size; i++) {
			if (m_arr[i]->getEntry() == m_arr[index]->getNext()->getEntry()) {
				repIndex = i;
			}
		}
		return findRepresentaive(repIndex);
	} else {
		return m_arr[index]->getEntry();
	}
}

template <typename T>
void DisjointSet<T>::PathCompression(int value) {

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
