#include <iostream>

#include "instances.hpp"
#include "sort_algorithms.hpp"
#include "runtime.hpp"

int main(int argc, char **argv) {

 
  // for (auto** end = instances + 3; instances != end; ++instances){
  //   print_instance<int>(*instances, 5);
  // }

  // instances = instances - 3;

  int instances_size = 1500;
  int amount_of_instances = 30000;

  auto** instances_1 = generate_n_instances<int, ascending_instance<int>>(instances_size, amount_of_instances);
  auto** instances_2 = generate_n_instances<int, descending_instance<int>>(instances_size, amount_of_instances);

  double time = run_instances<int, heap_sort<int>>(instances_1, instances_size, amount_of_instances);
  std::cout << "ascending final time: " << time << std::endl;  

  double time2 = run_instances<int, heap_sort<int>>(instances_2, instances_size, amount_of_instances);
  std::cout << "descending final time: " << time2 << std::endl;   
}