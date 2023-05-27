#ifndef INSTANCES_HPP
#define INSTANCES_HPP

#include "real_instances.hpp"

#include <iostream>
#include <cstdint>
#include <cstring>
#include <random>
#include <algorithm>


namespace substring_search {
namespace instances {

    std::random_device r_disp;
    std::mt19937 generator(r_disp());
    std::uniform_int_distribution<int> *distr = nullptr;

    inline void generate_random_instance(char *& pattern, char *& text, char l, int substr_size, int text_size){

        if (distr == nullptr) {
            char dif = l - 'a';
            distr = new std::uniform_int_distribution<int>(0, static_cast<int>(dif));
        }

        std::uniform_int_distribution<int> dist_v = *distr;

        char * end = pattern + substr_size;
        for (char * p = pattern; p != end; ++p){
            *p = 'a' + static_cast<char>(dist_v(generator));
        }

        end = text + text_size;
        for (char * p = text; p != end; ++p){
            *p = 'a' + static_cast<char>(dist_v(generator));
        }
    }

    inline void generate_real_instance(const char *& pattern, const char *& text, int i){

        pattern = Padroes_Palavras[i];
        text = Texto_Livros; 
    }

} //instances
} //substring_search

#endif