#include "heap.hpp"
#include "huffman_noh.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

int main() {

  std::ifstream source("compressed", std::ios_base::in |std::ios_base::binary);

  int n;
  source.get(reinterpret_cast<char *>(&n), sizeof(int));

  std::cout << n << std::endl;

  std::streampos next_seek = sizeof(int);
  source.seekg(next_seek);
  HuffmanNoh * huff_tree = new HuffmanNoh[(2 * n) - 1];
  //source.get(reinterpret_cast<char *>(huff_tree), (sizeof(HuffmanNoh) * ((2*n)-1)));
  std::cout << "size> " << sizeof(HuffmanNoh) << std::endl;
  for (int k = 0; k< 2*n -1; ++k){
    source.get(reinterpret_cast<char *>(&huff_tree[k]), sizeof(HuffmanNoh));
    next_seek += sizeof(HuffmanNoh);
    source.seekg(next_seek);
  }


  for (int i = 0; i < n; i++){
    std::cout << huff_tree[i].left << "|";
  }
  std::cout << std::endl;
  for (int j = n; j < 2*n - 1; j++){
    std::cout << huff_tree[j].left << "-" << huff_tree[j].right << "|";
  }
  std::cout << std::endl;

  return 0;


  // std::ifstream source("compressed", std::ios_base::binary);

  // char * nbuffer = new char[sizeof(int)];
  // source.get(nbuffer, sizeof(int));

  // int *np = reinterpret_cast<int*>(nbuffer);
  // int n = *np;

  // std::cout << n << std::endl;

  // source.seekg(4);
  // char * huff_tree_c = new char[(2 * n - 1) * sizeof(HuffmanNoh)];
  // source.get(huff_tree_c, sizeof(HuffmanNoh) * (2*n-1));
  
  // HuffmanNoh * huff_tree = reinterpret_cast<HuffmanNoh*>(huff_tree_c);
  
  // for (int i = 0; i < n; i++){
  //   std::cout << huff_tree[i].left << "|";
  // }
  // std::cout << std::endl;
  // for (int j = n; j < 2*n - 1; j++){
  //   std::cout << huff_tree[j].left << "-" << huff_tree[j].right << "|";
  // }
  // std::cout << std::endl;

  // return 0;

  // std::unordered_map<unsigned char, int> bytes_map;
  // std::ifstream source("bytes.txt", std::ios_base::binary);
  // std::ofstream compressed_file ("compressed", std::ios_base::binary);

  // unsigned char curr_byte = source.get();

  // while (curr_byte != 255) {
  //   bytes_map[curr_byte]++;
  //   curr_byte = source.get();
  // }

  // int n = bytes_map.size();

  // HuffmanNoh * huff_tree = new HuffmanNoh[2 * n - 1];
  // Heap<NohHeap> bytes_heap(n);
  
  // int curr_index = 0;
  // for (auto byte_occ : bytes_map) {
  //   huff_tree[curr_index] = HuffmanNoh(byte_occ.first);
  //   bytes_heap.add_element(NohHeap(curr_index++, byte_occ.second));
  // }

  // for (int i = n; i < 2*n - 1; ++i){
  //   NohHeap smallest = bytes_heap.get_first();
  //   NohHeap scnd_smallest = bytes_heap.get_first();
  //   huff_tree[i] = HuffmanNoh(smallest.index, scnd_smallest.index);

  //   NohHeap new_noh = NohHeap(i, smallest.weight + scnd_smallest.weight);
  //   bytes_heap.add_element(new_noh);
  // }

  // compressed_file.write(reinterpret_cast<char *>(&n), sizeof(int));
  // compressed_file.write(reinterpret_cast<char *>(huff_tree), sizeof(HuffmanNoh) * (2*n-1));
  // compressed_file.close();

  // for (int i = 0; i < n; i++){
  //   std::cout << huff_tree[i].left << "|";
  // }
  // std::cout << std::endl;
  // for (int j = n; j < 2*n - 1; j++){
  //   std::cout << huff_tree[j].left << "-" << huff_tree[j].right << "|";
  // }
  // std::cout << std::endl;

}