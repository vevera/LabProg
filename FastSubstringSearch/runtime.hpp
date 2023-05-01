#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include <iostream>
#include <cstdint>
#include <cstring>
#include <chrono>
#include <utility>


namespace substring_search {
namespace runtime {

template <void substring_search_algorithm(const char *, const char *, int *)>
double calculate_single_execution_run_time(const char *, const char *, int *){

    auto start = std::chrono::steady_clock::now();
    
    //substring_search_algorithm("a", "b", 0);
 
    auto end = std::chrono::steady_clock::now();

    // Calculating total time taken by the algorithm.
    std::chrono::duration<double> time_taken = end - start;
 
    return time_taken.count();
}

template <typename T, typename F, typename A>
std::pair<double, double> run_instances(F &&instance_generator, A &&allocator, int amount_of_instances){
    double total_run_time_bf{0};
    double total_run_time_kmp{0};
    double current_rt{0};

    T * pattern = nullptr;
    T * text = nullptr;
    int * occurrences = nullptr;

    auto deallocator = allocator(pattern, text, occurrences);
    
    for (int i = 0; i < amount_of_instances; i++){
        instance_generator(pattern, text, i);
        std::string p(pattern);
        std::cout << p << std::endl;
        //current_rt = calculate_single_execution_run_time<substring_search_algorithm>(instance, instance_size);
        total_run_time_bf = total_run_time_bf + current_rt;
    }
    
    deallocator();

    return std::make_pair(total_run_time_bf, total_run_time_kmp);
}

} //runtime
} //substring_search

#endif