#ifndef INSTANCES_HPP
#define INSTANCES_HPP

#include <iostream>
#include <cstdlib>

#include "pivot.hpp"
#include "swap.hpp"

template <typename T>
void print_instance(T*& instance, int instance_size){

  auto* iterator = instance;

  for (T* end = iterator + instance_size; iterator != end; ++iterator){
    std::cout << *iterator << "|";
  }

  std::cout << std::endl;
}

template <typename T, bool instance_generator(T*&, int)>
T** generate_n_instances(int instance_size, int amount_of_instances){

  T** instances_array = new T*[amount_of_instances];
  
  for (T** end = instances_array + amount_of_instances; instances_array != end; ++instances_array){
    instance_generator(*instances_array, instance_size);
  }

  return instances_array - amount_of_instances;
}

template <typename T>
bool random_instance(int*& vector, int n){

  srand((unsigned) time(NULL));
  int random;

  vector = new T[n];
  T* vec_cur = vector;

  for (T *end = vec_cur + n; vec_cur != end; ++vec_cur) {
    *vec_cur = 1 + rand() % n;
  }

  return false;
}

template <typename T>
bool worst_case_instance(T*& vector, int n){

  vector = new T[n];
  int pivot_{0};
  T next_value{1};

  T** v_ptr2 = new T*[n];

  T** v_ptr2_c = v_ptr2;
  T* v_ptr_current = vector;

  for (T** end_ptr = v_ptr2_c + n; v_ptr2_c != end_ptr; ++v_ptr2_c) {
    *v_ptr2_c = v_ptr_current++;
  }

  for (int start = 0; start <= n-1; start++) {
    pivot_ = pivot(start, n-1);
    *v_ptr2[pivot_] = next_value++;
    swap<T*>(v_ptr2[start], v_ptr2[pivot_]);
  }

  delete[] v_ptr2;

  return true;
}

template <typename T>
bool ascending_instance(int*& vector, int n){

  vector = new T[n];

  T* vec_cur = vector;
  T inc{1};

  for (T *end = vec_cur + n; vec_cur != end; ++vec_cur) {
    *vec_cur = inc++;
  }

  return false;
}

template <typename T>
bool descending_instance(int*& vector, int n){

  vector = new T[n];

  T* vec_cur = vector;
  T inc{n};

  for (T *end = vec_cur + n; vec_cur != end; ++vec_cur) {
    *vec_cur = inc--;
  }

  return false;
}

#endif