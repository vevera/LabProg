#include "instances.hpp"
#include "real_instances.hpp"
#include "substring_search_algs.hpp"
#include "runtime.hpp"

#include <cstring>
#include <iostream>
#include <functional>
#include <utility>
//#include <string>



int main(int argc, char **argv){

  char instance_type;
  char l;
  int substr_size, text_size, iterations, x, y;
  std::pair<double, double> run_times{0, 0};

  instance_type = *argv[1];
  
  if (instance_type == 'A') {

    l = *argv[2];
    substr_size = std::stoi(argv[3]);
    text_size = std::stoi(argv[4]);
    iterations = std::stoi(argv[5]);

    auto random_generator = [&l, &substr_size, &text_size](char* P_, char* T_, int)-> void {
      substring_search::instances::generate_random_instance(P_, T_, l, substr_size, text_size);
    };

    auto random_allocator = [&substr_size, &text_size](char*& P_, char*& T_, int *& O_){
      P_ = new char[substr_size];
      T_ = new char[text_size];
      O_ = new int[text_size];

      auto deallocator = [P_, T_, O_](){
        delete[] P_;
        delete[] T_;
        delete[] O_;
      };

      return deallocator;
    }; 

    run_times = substring_search::runtime::run_instances<char>(random_generator, random_allocator, iterations);

  }

  if (instance_type == 'R'){

    x = std::stoi(argv[2]);
    y = std::stoi(argv[3]);
    iterations = y - x + 1;

    auto real_generator = [&x](const char*& P_, const char*& T_, int i)-> void {
      int real_i = x + i;
      substring_search::instances::generate_real_instance(P_, T_, real_i);
    };

    auto real_allocator = [](const char*&, const char*&, int *& O_){
      size_t size = strlen(Texto_Livros);
      O_ = new int[size];

      auto deallocator = [O_](){
        delete[] O_;
      };

      return deallocator;
    };

    run_times = substring_search::runtime::run_instances<const char>(real_generator, real_allocator, iterations);
  }

  std::cout << "Brute force total time: " << run_times.first << "\n";
  std::cout << "KMP total time: " << run_times.first << "\n";
  return 0;
}