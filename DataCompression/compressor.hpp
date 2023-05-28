#ifndef COMPRESSOR_HPP
#define COMPRESSOR_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "heap.hpp"
#include "huffman_noh.hpp"

typedef std::unordered_map<unsigned char, std::vector<unsigned char>> codes;

void huff_tree_traversal(HuffmanNoh* root, size_t inx, size_t n, codes & bytes_codes, std::vector<unsigned char> & curr_code){

    if (inx < n) {
        bytes_codes[root[inx].left] = curr_code;
        return;
    }

    curr_code.push_back('0');   
    huff_tree_traversal(root, root[inx].left, n, bytes_codes, curr_code);
    curr_code.pop_back();

    curr_code.push_back('1');   
    huff_tree_traversal(root, root[inx].right, n, bytes_codes, curr_code);
    curr_code.pop_back(); 
}

codes bytes_huffman_code(HuffmanNoh* huff_tree, size_t lenght) {

    codes bytes_codes;
    std::vector<unsigned char> curr_code;
    
    huff_tree_traversal(huff_tree, lenght - 1, (lenght - 1)/2, bytes_codes, curr_code);    

    return bytes_codes;
}

void compressor(std::string file_name){

  std::unordered_map<unsigned char, int> bytes_map;
  std::ifstream source(file_name.data(), std::ios_base::in | std::ios_base::binary);
  std::ofstream compressed_file ("compressed", std::ios_base::out | std::ios_base::binary);

  unsigned char curr_byte = source.get();

  while (curr_byte != 255) {
    bytes_map[curr_byte]++;
    curr_byte = source.get();
  }

  source.close();

  int n = bytes_map.size();

  HuffmanNoh * huff_tree = new HuffmanNoh[2 * n - 1];
  Heap<NohHeap> bytes_heap(n);

  int curr_index = 0;
  for (auto byte_occ : bytes_map) {
    huff_tree[curr_index] = HuffmanNoh(byte_occ.first);
    bytes_heap.add_element(NohHeap(curr_index++, byte_occ.second));
  }

  for (int i = n; i < 2*n - 1; ++i){
    NohHeap smallest = bytes_heap.get_first();
    NohHeap scnd_smallest = bytes_heap.get_first();
    huff_tree[i] = HuffmanNoh(smallest.index, scnd_smallest.index);

    NohHeap new_noh = NohHeap(i, smallest.weight + scnd_smallest.weight);
    bytes_heap.add_element(new_noh);
  }

  codes bytes_codes = bytes_huffman_code(huff_tree, 2*n-1);
    
  compressed_file.write(reinterpret_cast<char *>(&n), sizeof(int));
  compressed_file.write(reinterpret_cast<char *>(huff_tree), sizeof(HuffmanNoh) * (2*n-1));
  compressed_file.close();
  source.close();

//   for (int i = 0; i < n; i++){
//     std::cout << huff_tree[i].left << "|";
//   }
//   std::cout << std::endl;
//   for (int j = n; j < 2*n - 1; j++){
//     std::cout << huff_tree[j].left << "-" << huff_tree[j].right << "|";
//   }
//   std::cout << std::endl;

}

#endif //COMPRESSOR_HPP