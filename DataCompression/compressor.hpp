#ifndef COMPRESSOR_HPP
#define COMPRESSOR_HPP

#include <bitset>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>

#include "heap.hpp"
#include "huffman_noh.hpp"

typedef std::unordered_map<unsigned char, std::vector<unsigned char>> codes;

constexpr char kFirstBitOneMask = 0x7F; //01111111

void huff_tree_traversal(HuffmanNoh* root, size_t inx, size_t n, codes & bytes_codes, std::vector<unsigned char> & curr_code){

    if (inx < n) {
        bytes_codes[root[inx].left] = curr_code;
        return;
    }

    curr_code.push_back('1');   
    huff_tree_traversal(root, root[inx].left, n, bytes_codes, curr_code);
    curr_code.pop_back();

    curr_code.push_back('0');   
    huff_tree_traversal(root, root[inx].right, n, bytes_codes, curr_code);
    curr_code.pop_back(); 
}

codes bytes_to_huffman_code(HuffmanNoh* huff_tree, size_t lenght) {

    codes bytes_codes;
    std::vector<unsigned char> curr_code;
    
    huff_tree_traversal(huff_tree, lenght - 1, (lenght + 1)/2, bytes_codes, curr_code);    

    return bytes_codes;
}

void compressor(std::string file_name, std::string outputfile){
  //auto start_time = std::chrono::steady_clock::now();

  HuffmanNoh * huff_tree;
  int n;
  int qtd_bytes{0};
  std::ofstream compressed_file (outputfile.data(), std::ios_base::out | std::ios_base::binary);
  std::vector<char> bytes_to_read;
  
  {

    std::unordered_map<unsigned char, int> bytes_map;
    std::ifstream source(file_name.data(), std::ios_base::in | std::ios_base::binary);

    while (source.peek() != EOF) {
      ++qtd_bytes;
      bytes_map[source.get()]++;
    } 
  
    n = bytes_map.size();
    
    if (n == 0) {
      compressed_file.close();
      return;
    }
    if (n == 1) {
      char element = bytes_map.begin()->first;
      compressed_file.write(reinterpret_cast<char *>(&n), sizeof(int));
      compressed_file.write(reinterpret_cast<char *>(&qtd_bytes), sizeof(int));
      compressed_file.write(reinterpret_cast<char *>(&element), sizeof(char));
      compressed_file.close();
      return;
    }
  
    huff_tree = new HuffmanNoh[2 * n - 1];
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
  }

  compressed_file.write(reinterpret_cast<char *>(&n), sizeof(int));
  compressed_file.write(reinterpret_cast<char *>(&qtd_bytes), sizeof(int));
  compressed_file.write(reinterpret_cast<char *>(huff_tree), sizeof(HuffmanNoh) * (2*n-1));
  
  codes bytes_codes = bytes_to_huffman_code(huff_tree, 2*n-1);

  unsigned char curr_byte;
  char byte_to_write{0};
  unsigned char shifts_count{0};
  std::vector<unsigned char> byte_code;
  bool last_write = false;

  std::ifstream source(file_name.data(), std::ios_base::in | std::ios_base::binary);

  while (source.peek() != EOF) {
    curr_byte = source.get();
    byte_code = bytes_codes.find(curr_byte)->second;
    for (size_t i = 0; i < byte_code.size(); ++i){
        byte_to_write = (byte_to_write << 1) | (byte_code.at(i) == '1'); 
        ++shifts_count;

        if (source.peek() == EOF && i == byte_code.size() - 1){
          byte_to_write = byte_to_write << (8 - shifts_count);
          last_write = true;
        }
        if (shifts_count == 8 || last_write) {
          shifts_count = 0;
          compressed_file.write(&byte_to_write, sizeof(unsigned char));
          byte_to_write = 0;
        }
    }
  }

  //std::cout << std::chrono::duration<double>(std::chrono::steady_clock::now() - start_time).count() << std::endl;
  
  source.close();
  compressed_file.close();
}

void read_compressed_file(std::string file_name, std::string outputfile){

  std::ifstream source(file_name.data(), std::ios_base::in | std::ios_base::binary);
  std::ofstream output (outputfile.data(), std::ios_base::out | std::ios_base::binary);

  int n, qtd_bytes;
  std::streampos next_seek = 0;

  source.read(reinterpret_cast<char *>(&n), sizeof(int));
  next_seek += sizeof(int);
  source.seekg(next_seek);

  source.read(reinterpret_cast<char *>(&qtd_bytes), sizeof(int));
  next_seek += sizeof(int);
  source.seekg(next_seek);

  if (n == 0) {
    output.close();
    return;
  }

  if (n == 1){
    char byte = source.get();
    for (int i = 0; i<qtd_bytes; ++i){
      output.write(&byte, sizeof(char));
    }
    output.close();
    return;
  }

  HuffmanNoh *huff_tree = new HuffmanNoh[(2 * n) - 1];

  source.read(reinterpret_cast<char *>(huff_tree), sizeof(HuffmanNoh) * (2*n-1));  
  next_seek += sizeof(HuffmanNoh) * (2*n-1);
  source.seekg(next_seek);

  int root_idx{2*n-2};
  int bytes_written{0};
  
  unsigned char file_byte{0};
  char shift_count{0};
  char actual_byte{0};

  while (bytes_written < qtd_bytes) {
    file_byte = source.get();
    shift_count = 0;

    while(shift_count!=8 && (bytes_written < qtd_bytes)){
      if (root_idx < n){
        actual_byte = huff_tree[root_idx].left;
        output.write(&actual_byte, sizeof(char));
        root_idx = 2*n-2;
        ++bytes_written;
      }
      if ((file_byte | kFirstBitOneMask) == 255){ 
        root_idx = huff_tree[root_idx].left;
      }
      else{
        root_idx = huff_tree[root_idx].right;
      }
      ++shift_count;
      file_byte = file_byte << 1;
    }
  }
  
  source.close();
  output.close();
}
#endif //COMPRESSOR_HPP