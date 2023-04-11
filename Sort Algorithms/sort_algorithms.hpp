#ifndef SORT_ALGORITHMS_HPP
#define SORT_ALGORITHMS_HPP

#include <iostream>
#include "pivot.hpp"
#include "swap.hpp"
#include "instances.hpp"

template <typename T>
T* heap_sort(T* vector, int n){
  //print_instance(vector, n);
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

template <typename T, int pivot_fun(int, int)>
int partition(T* vector, int low, int high){

  int r = pivot_fun(low, high);
  swap<T>(vector[r], vector[high]);

  T pivot = vector[high];
  int i = (low - 1);

  for (int j = low; j <= high- 1; j++)
  {
      // If current element is smaller than or
      // equal to pivot
      if (vector[j] <= pivot)
      {
          i++;    // increment index of smaller element
          swap<T>(vector[i], vector[j]);
      }
  }
  swap(vector[i + 1], vector[high]);
  return (i + 1);
}

template<typename T, int pivot_fuc(int, int)>
void internal_quick_s(T* vector, int low, int high){
  if (low < high)
    {
        int pi = partition<T, pivot_fuc>(vector, low, high);
 
        internal_quick_s<T, pivot_fuc>(vector, low, pi - 1);
        internal_quick_s<T, pivot_fuc>(vector, pi + 1, high);
    }
}

template <typename T>
T* quick_sort(T* vector, int n){
  internal_quick_s<T, pivot>(vector, 0, n-1);
  return vector;
}

template <typename T>
T* random_quick_sort(T* vector, int n){
  internal_quick_s<T, pivot_r>(vector, 0, n-1);
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