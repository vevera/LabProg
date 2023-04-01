#include <exception>
#include <iostream>

#include "instances.hpp"
#include "sort_algorithms.hpp"
#include "runtime.hpp"

int main(int argc, char **argv) {

  int instances_size, amount_of_instances;
  double time_heap_sort, time_random_quick, time_quick, time_intro, time_intro_insertion;
  std::string instance_type;

  if (argc != 4) {
    std::cout << "Invalid Argument Size!!!\n";
  }

  try{
    instance_type = argv[1];
    instances_size = std::stoi(argv[2]);
    amount_of_instances = std::stoi(argv[3]);
  }
  catch(std::exception e){
    std::cout << "Invalid Arguments!!\n";
    std::cout << e.what() << std::endl;
  }

  auto instance = get_instance<int>(instance_type, instances_size);

  time_heap_sort = run_instances<int, heap_sort<int>>(instance, instances_size, amount_of_instances);
  std::cout << "HeapSort Took " << time_heap_sort << " s to run " << amount_of_instances << " instances!\n";  

  time_random_quick = run_instances<int, random_quick_sort<int>>(instance, instances_size, amount_of_instances);
  std::cout << "RandomQuick Sort Took " << time_random_quick << " s to run " << amount_of_instances << " instances!\n";  

  time_quick = run_instances<int, quick_sort<int>>(instance, instances_size, amount_of_instances);
  std::cout << "QuickSort Took " << time_quick << " s to run " << amount_of_instances << " instances!\n";  

  time_intro = run_instances<int, introsort<int>>(instance, instances_size, amount_of_instances);
  std::cout << "Introsort Took " << time_intro << " s to run " << amount_of_instances << " instances!\n";  

  time_intro_insertion = run_instances<int, introsort_with_insertion<int>>(instance, instances_size, amount_of_instances);
  std::cout << "Introsort with insertion Took " << time_intro_insertion << " s to run " << amount_of_instances << " instances!\n";
}