#ifndef SORT_ALGORITHMS_HPP
#define SORT_ALGORITHMS_HPP

#include <iostream>
#include "pivot.hpp"
#include "swap.hpp"
#include "instances.hpp"

template <typename T>
T* heap_sort(T* vector, int n){

  auto heapify = [&vector](int i, int v_size){

    bool heapified = false;
    int largest;
    int left;
    int right;

    while(!heapified){
      largest = i;
      left = 2 * i + 1;
      right = 2 * i + 2;

      if (left < v_size && vector[left] > vector[largest])
        largest = left;

      if (right < v_size && vector[right] > vector[largest])
        largest = right;

      if (largest != i) {
        swap<T>(vector[i], vector[largest]);
        i = largest;
      }
      else
        heapified = true;     
    }
  };

  for (int i = n / 2 - 1; i >= 0; i--){
    heapify(i, n);
  }

  for (int i = n - 1; i >= 0; i--) {
      swap<T>(vector[0], vector[i]);
      heapify(0, i);
  }
  //print_instance(vector, n);
  return vector;
}

template <typename T>
T* quick_sort(T* vector, int n){
  for (int i = 0; i<10000000; i++){
    
  }
  return vector;
}

template <typename T>
T* random_quick_sort(T* vector, int n){
  return vector;  
}

template <typename T>
T* introsort(T* vector, int n){
  return vector;  
}

template <typename T>
T* introsort_with_insertion(T* vector, int n){
  return vector;  
}

#endif