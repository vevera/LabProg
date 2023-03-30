#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include <iostream>
#include <cstdint>
#include <cstring>
#include <chrono>

template <typename T, T* sort_algorithm(T*, int)>
double calculate_single_execution_run_time(T* vector, int n){

    size_t size = n * sizeof(T);

    T* copy_vector = new T[n];
    std::memcpy(copy_vector, vector, size);

    auto start = std::chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    std::ios_base::sync_with_stdio(false);
 
    sort_algorithm(copy_vector, n);
 
    auto end = std::chrono::high_resolution_clock::now();

    delete[] copy_vector;
 
    // Calculating total time taken by the program.
    double time_taken =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
 
    time_taken *= 1e-9;

    return time_taken;
}

template <typename T, T* sort_algorithm(T*, int)>
double run_instances(T** instances, int instance_size, int amount_of_instances){
    double total_run_time{0};
    double current_rt;
    
    for (T** end = instances + amount_of_instances; instances != end; ++instances){
        current_rt = calculate_single_execution_run_time<T, sort_algorithm>(*instances, instance_size);
        total_run_time = total_run_time + current_rt;
    }

    return total_run_time;
}


#endif