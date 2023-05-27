#ifndef HEAP_HPP
#define HEAP_HPP

#include <stdio.h>
#include <math.h>  
#include <iostream>

template <typename T>
void swap(T& a, T& b){
    T aux = a;
    a = b;
    b = aux;
}

template <class T>
class Heap {

  public:
    Heap(size_t heap_size);
    void add_element(T element);
    T get_first();
    void print_heap();
  
  private:
    void heapify(size_t start_i, size_t arr_length);
    void heapify_bottomup(size_t start_i, size_t arr_length);
    size_t last_index;
    T* buffer;
  
};

template <class T>
Heap<T>::Heap(size_t heap_size) : buffer{new T[heap_size]}, last_index{0} {}

template <class T>
void Heap<T>::add_element(T element) {
  buffer[last_index] = element;
  heapify_bottomup(last_index++, last_index + 1);
}

template <class T>
T Heap<T>::get_first() {
  T element = buffer[0];
  swap(buffer[0], buffer[--last_index]);
  heapify(0, last_index);
  return element;
}

template <class T>
void Heap<T>::heapify(size_t start_i, size_t arr_length){
  
    bool heapified = false;
    int smallest;
    int left;
    int right;

    while(!heapified) {
      smallest = start_i;
      left = 2 * start_i + 1;
      right = 2 * start_i + 2;

      if (left < arr_length && buffer[left] < buffer[smallest])
        smallest = left;

      if (right < arr_length && buffer[right] < buffer[smallest])
        smallest = right;

      if (smallest != start_i) {
        swap<T>(buffer[start_i], buffer[smallest]);
        start_i = smallest;
      }
      else
        heapified = true;     
    }
}

template <class T>
void Heap<T>::heapify_bottomup(size_t start_i, size_t arr_length){
    bool heapified = false;
    int parent;

    while(!heapified) {
      parent = ceil(start_i/2.0 - 1.0);

      if (start_i < arr_length && parent >= 0 && buffer[parent] > buffer[start_i]) {
        swap<T>(buffer[start_i], buffer[parent]);
        start_i = parent;
      }
      else { 
        heapified = true; 
      } 
    }
}


template <class T>
void Heap<T>::print_heap(){
  
    for (int i = 0; i < last_index; ++i){
      std::cout << buffer[i] << "|";
    }
    std::cout << std::endl;
}

#endif //HEAP_HPP