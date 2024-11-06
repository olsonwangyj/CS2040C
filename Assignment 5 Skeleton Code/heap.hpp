#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef HEAPHPP
#define HEAPHPP

#define DEFAULTHEAPSIZE 1023

template <class T>
class Heap {
private:
    int _size = 0;

 protected:
  T* _heap;
  

 public:
  Heap() { _heap = new T[DEFAULTHEAPSIZE]; }

  int size() const {
    // TODO: implement this
    return _size;
  }

  bool empty() const {
    // TODO: implement this
    return _size == 0;
  }
  void insert(const T&);
  T extractMax();
  T peekMax() const;
  void printHeapArray() const;
  void printTree() const;
  void changeKey(const T& from, const T& to);
  void deleteItem(const T&);

  ~Heap() { delete[] _heap; };


private:
    void bubbleUp(int index);
    void bubbleDown(int index);
    int findIndex(const T& item);
};

template <class T>
void Heap<T>::bubbleUp(int index) {
    while (index > 0 && _heap[index] > _heap[(index - 1) / 2]) {
        std::swap(_heap[index], _heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

template <class T>
void Heap<T>::bubbleDown(int index) {
    while (index < _size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        if (leftChild >= _size) break;

        int largerChild = leftChild;
        if (rightChild < _size && _heap[rightChild] > _heap[leftChild]) {
            largerChild = rightChild;
        }

        if (_heap[index] >= _heap[largerChild]) break;

        std::swap(_heap[index], _heap[largerChild]);
        index = largerChild;
    }

}


template <class T>
void Heap<T>::insert(const T& item) {
  // TODO: implement this
    _heap[_size] = item;
    bubbleUp(_size);
    _size++;
}

template <class T>
T Heap<T>::extractMax() {
  // TODO: implement this
    if (empty()) throw std::out_of_range("empty");

    T max = _heap[0];
    _heap[0] = _heap[_size - 1];
    _size--;
    bubbleDown(0);

    return max;
}

template <class T>
T Heap<T>::peekMax() const {
  // TODO: What happens if the heap is empty?
    if (empty()) throw std::out_of_range("empty");

    return _heap[0];
};

template <class T>
void Heap<T>::printHeapArray() const {
  for (int i = 0; i < size(); i++) {
    cout << _heap[i] << " ";
  }
  cout << endl;
}

template <class T>
int Heap<T>::findIndex(const T& item) {
    for (int i = 0; i < _size; i++) {
        if (_heap[i] == item) {
            return i;
        }
    }

    throw std::out_of_range("not found");
}

template <class T>
void Heap<T>::changeKey(const T& from, const T& to) {
  // TODO: implement this
    if (empty()) throw std::out_of_range("empty");

    int index = findIndex(from);
    _heap[index] = to;
    if (from > to) {
        bubbleDown(index);
    }
    else {
        bubbleUp(index);
    }
}

template <class T>
void Heap<T>::deleteItem(const T& x) {
  // TODO: implement this
    if (empty()) throw std::out_of_range("empty");

    int index = findIndex(x);
    _heap[index] = _heap[_size - 1];
    _size--;
    bubbleDown(index);
}

template <class T>
void Heap<T>::printTree() const {
  int parity = 0;
  if (size() == 0) return;
  int space = pow(2, 1 + (int)log2f(size())), i;
  int nLevel = (int)log2f(size()) + 1;
  int index = 0, endIndex;
  int tempIndex;

  for (int l = 0; l < nLevel; l++) {
    index = 1;
    parity = 0;
    for (i = 0; i < l; i++) index *= 2;
    endIndex = index * 2 - 1;
    index--;
    tempIndex = index;
    while (index < size() && index < endIndex) {
      for (i = 0; i < space - 1; i++) cout << " ";
      if (index == 0)
        cout << "|";
      else if (parity)
        cout << "\\";
      else
        cout << "/";
      parity = !parity;
      for (i = 0; i < space; i++) cout << " ";
      index++;
    }
    cout << endl;
    index = tempIndex;
    while (index < size() && index < endIndex) {
      for (i = 0; i < (space - 1 - ((int)log10(_heap[index]))); i++)
        cout << " ";
      cout << _heap[index];
      for (i = 0; i < space; i++) cout << " ";
      index++;
    }

    cout << endl;
    space /= 2;
  }
}

#endif
