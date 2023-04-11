#ifndef PIVOT_HPP
#define PIVOT_HPP

#include "myrandomgen.hpp"

int pivot(int start, int end){
  
  return end;
}

int pivot_r(int start, int end){

  auto mygen = MyRandomGen::instance();
  mygen->change_interval(start, end);

  return mygen->generate();
}

#endif