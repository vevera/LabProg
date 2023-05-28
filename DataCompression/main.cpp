#include "heap.hpp"
#include "huffman_noh.hpp"
#include "compressor.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

int main() {

  // {
  //   std::ifstream source("compressed", std::ios_base::in | std::ios_base::binary);
  //   int n;
  //   source.read(reinterpret_cast<char *>(&n), sizeof(int));

  //   std::cout << n << std::endl;

  //   std::streampos next_seek = sizeof(int);
  //   source.seekg(next_seek);

  //   HuffmanNoh *huff_tree = new HuffmanNoh[(2 * n) - 1];
  //   source.read(reinterpret_cast<char *>(huff_tree), (sizeof(HuffmanNoh) * (2*n-1)));
    

  //   for (int i = 0; i < n; i++) {
  //     std::cout << huff_tree[i].left << "|";
  //   }
  //   std::cout << std::endl;
  //   for (int j = n; j < 2 * n - 1; j++) {
  //     std::cout << huff_tree[j].left << "-" << huff_tree[j].right << "|";
  //   }
  //   std::cout << std::endl;
  // }

  // return 0;

  compressor("bytes.txt");

}