#include "instances.hpp"
#include "real_instances.hpp"
#include "substring_search_algs.hpp"
#include "runtime.hpp"

#include <cstring>
#include <iostream>
#include <functional>
#include <utility>
//#include <string>

constexpr char kRandomInstance = 'A';
constexpr char kRealInstance = 'R';

int main(int, char **argv){

  char instance_type, l;
  int substr_size, text_size, iterations, x, y;
  std::pair<double, double> run_times{0, 0};

  instance_type = *argv[1];
  
  if (instance_type == kRandomInstance) {

    l = *argv[2];

    try {
       substr_size = std::stoi(argv[3]);
       text_size = std::stoi(argv[4]);
       iterations = std::stoi(argv[5]);
    }
    catch(std::out_of_range &e){
      std::cout << "std::stoi out of range\n";
      return  0;
    }

    auto generator = [&l, &substr_size, &text_size](char* P_, char* T_, int)-> void {
      substring_search::instances::generate_random_instance(P_, T_, l, substr_size, text_size);
    };

    auto allocator = [&substr_size, &text_size](char*& P_, char*& T_, int *& O_bf, int *& O_kmp){
      P_ = new char[substr_size];
      T_ = new char[text_size];
      O_bf = new int[text_size + 1];
      O_kmp = new int[text_size + 1];

      auto deallocator = [P_, T_, O_bf, O_kmp](){
        delete[] P_;
        delete[] T_;
        delete[] O_bf;
        delete[] O_kmp;
      };

      return deallocator;
    }; 

    try {
      run_times = substring_search::runtime::run_instances<char>(generator, allocator, iterations);
    }
    catch(std::bad_alloc &e){
      std::cout << "Erro na alocação de memoria!!\n";
      return 0;
    }
  }

  if (instance_type == kRealInstance){

    try {
       x = std::stoi(argv[2]);
       y = std::stoi(argv[3]);
    }
    catch(std::out_of_range &e){
      std::cout << "std::stoi out of range\n";
      return  0;
    }

    iterations = y - x + 1;

    auto generator = [x](const char*& P_, const char*& T_, int i)-> void {
      int real_i = x + i;
      substring_search::instances::generate_real_instance(P_, T_, real_i);
    };

    auto allocator = [](const char*&, const char*&, int *& O_bf, int *& O_kmp){
      size_t size = strlen(Texto_Livros);
      O_bf = new int[size + 1];
      O_kmp = new int[size + 1];

      auto deallocator = [O_bf, O_kmp](){
        delete[] O_bf;
        delete[] O_kmp;
      };

      return deallocator;
    };

    try {
      run_times = substring_search::runtime::run_instances<const char>(generator, allocator, iterations);
    }
    catch(std::bad_alloc &e){
      std::cout << "Erro na alocação de memoria!!\n";
      return 0;
    }

  }

  std::cout << "Brute force total time: " << run_times.first << "\n";
  std::cout << "KMP total time: " << run_times.second << "\n";
  return 0;
}