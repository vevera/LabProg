#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include <iostream>
#include <cstdint>
#include <cstring>
#include <chrono>
#include <utility>

#include "substring_search_algs.hpp"


namespace substring_search {
namespace runtime {

bool compare_occurrences(int * occurrences_bf, int * occurrences_kmp) {

    int * cur_bf = occurrences_bf;
    int * cur_kmp = occurrences_kmp;
    
    for (cur_bf; *cur_bf != -1; ++cur_bf){
        if (*cur_bf != *cur_kmp) return false;
        ++cur_kmp;
    }

    if (*cur_kmp != -1) return false;

    return true;

}

template <void substring_search_algorithm(const char *, const char *, int *)>
double calculate_single_execution_run_time(const char *P, const char * T, int *O){

    auto start = std::chrono::steady_clock::now();
    
    substring_search_algorithm(P, T, O);
 
    auto end = std::chrono::steady_clock::now();

    // Calculating total time taken by the algorithm.
    std::chrono::duration<double> time_taken = end - start;
 
    return time_taken.count();
}

template <typename T, typename F, typename A>
std::pair<double, double> run_instances(F &&instance_generator, A &&allocator, int amount_of_instances){
    double total_run_time_bf{0};
    double total_run_time_kmp{0};

    T * pattern = nullptr;
    T * text = nullptr;
    int * occurrences_bf = nullptr;
    int * occurrences_kmp = nullptr;

    auto deallocator = allocator(pattern, text, occurrences_bf, occurrences_kmp);
    
    for (int i = 0; i < amount_of_instances; i++){
        instance_generator(pattern, text, i);
        total_run_time_bf = total_run_time_bf + 
                            calculate_single_execution_run_time<substring_search::algorithms::brute_force>(pattern, text, occurrences_bf);
        total_run_time_kmp = total_run_time_kmp + 
                            calculate_single_execution_run_time<substring_search::algorithms::KMP>(pattern, text, occurrences_kmp);

        if (!compare_occurrences(occurrences_bf, occurrences_kmp)) {
            std::cout << "Os vetores de ocorrencias foram diferentes!!\n";
            break;
        }

    }
    
    deallocator();

    return std::make_pair(total_run_time_bf, total_run_time_kmp);
}
} //runtime
} //substring_search

#endif