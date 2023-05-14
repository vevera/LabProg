#ifndef SUBSTRING_SEARCH_ALGS_HPP
#define SUBSTRING_SEARCH_ALGS_HPP

#include <cstring>
#include <iostream>  
#include <functional>
#include "real_instances.hpp"

namespace substring_search {

namespace algorithms {

    constexpr char kStringLastElement = '\0';

    template <typename T>
    inline void print_vector(T *v, int size) {
        for (T* f = v + size; v != f; ++v){
            std::cout << *v << "|";
        }
        std::cout << std::endl;
    }

    inline void brute_force (const char *P, const char *T, int *O){

        int O_i{0};
        int pi{0};
        int ti{0};

        for (ti = 0; T[ti] != kStringLastElement; ti++){
            for (pi = 0; P[pi] != kStringLastElement; pi++){
                if (T[ti + pi] != P[pi]) {
                    break;
                }
            }
            if (P[pi] == kStringLastElement) {
                O[O_i++] = ti;
            }
        }  
        O[O_i] = -1;

        return;
    }

    inline void fill_A(const char * pattern, int * A) {

        std::function<void(int, int)> assign_values;
        assign_values = [&pattern, &A, &assign_values](int i, int k){
            if (pattern[i + 1] == pattern[k + 1]) {
                A[i + 1] = k + 1;
            }
            else if (k == -1) {
                A[i + 1] = -1;
            }
            else {
                int k_ = A[k];
                assign_values(i, k_);
            }
        };

        int pattern_size = strlen(pattern);

        A[0] = -1;
        for (int i = 0; i < pattern_size - 1; i++){
            assign_values(i, A[i]);
        }
    }
    
    //Knuth–Morris–Pratt algorithm
    inline void KMP (const char *P, const char *T, int *O){

        int P_size = strlen(P);
        int T_size = strlen(T);

        int * A = new int[P_size];
        fill_A(P, A);

        //print_vector(A, P_size);
        
        int O_i{0};
        int p{0};
        int i{-1};
        int K{0};

        while (p + i + 1 < T_size) {
            if (T[p + i + 1] == P[i + 1]) {
                if (i + 1 != P_size - 1) ++i;
                else if (i + 1 == P_size - 1) {
                    O[O_i++] = p;
                    K = A[i + 1];
                    p = p + i + 1 - K;
                    i = K;
                }
            }
            else if (T[p + i + 1] != P[i + 1]) {
                if (i != -1) {
                    K = A[i];
                    p = p + i - K;
                    i = K;
                }
                else if (i == -1) ++p;
            }
        }
        O[O_i] = -1;

        delete A;
    }

} //algorithms   
} //substring_search

#endif