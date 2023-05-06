#ifndef SUBSTRING_SEARCH_ALGS_HPP
#define SUBSTRING_SEARCH_ALGS_HPP

#include <cstring>
#include <iostream>
#include "real_instances.hpp"

namespace substring_search {

namespace algorithms {

    constexpr char kStringLastElement = '\0';

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
                O[O_i] = ti;
                O_i++;
            }
        }
        O[O_i] = -1;

        return;
    }

    inline void fill_A(const char * pattern, int * A) {

        A[0] = -1;
        int K;
        bool kEqualNegativeOne = true;
        for (int i = 0; i < strlen(pattern) - 1; i++){
            K = kEqualNegativeOne? A[i] : A[K];
            if (pattern[i + 1] == pattern[K + 1]) {
                A[i + 1] = K + 1;
            }
            else {
                if (K == -1) {
                    A[i + 1] = -1;
                }
                else {
                    kEqualNegativeOne = false;
                }
            }
        }
    }

    //Knuth–Morris–Pratt algorithm
    inline void KMP (const char *P, const char *T, int *O){

        size_t P_size = strlen(P);
        size_t T_size = strlen(T);

        int * A = new int[P_size];

        fill_A(P, A);
        
        int O_i{0};
        int p{0};
        int i{-1};
        int K{0};

        while (p + i + 1 < T_size) {
            if (T[p + i + 1] == P[i + 1]) {
                if (i + 1 != P_size - 1) {
                    i += 1;
                }
                else if (i + 1 == P_size - 1) {
                    O[O_i] = p;
                    O_i++;
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
                else if (i == -1) {
                    p += 1;
                }
            }
        }
        O[O_i] = -1;

        delete A;
        return;
    }
} //algorithms   
} //substring_search

#endif