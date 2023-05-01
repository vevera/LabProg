#ifndef INSTANCES_HPP
#define INSTANCES_HPP

#include "real_instances.hpp"

#include <iostream>
#include <cstdint>
#include <cstring>


namespace substring_search {
namespace instances {

    inline void generate_random_instance(char *& pattern, char *& text, char l, int substr_size, int text_size){

        std::cout << "GENERATE RANDOM INSTANCE\n";
        // pattern = 'o', 'l', 'a', '\0'};
        // text = "mundo";
    }

    inline void generate_real_instance(const char *& pattern, const char *& text, int i){

        std::cout << "GENERATE REAL INSTANCE\n";
        pattern = Padroes_Palavras[i];
        text = Texto_Livros;
    }

} //instances
} //substring_search

#endif