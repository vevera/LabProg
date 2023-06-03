#include "compressor.hpp"
#include "heap.hpp"
#include "huffman_noh.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

int main(int argc, char **argv) {

  if (argc != 4) {
    std::cout << "Invalid arguments size!!\n";
    return 0;
  }

  std::string cmd = argv[1];

  if (cmd == "-c") {
    compressor(std::string(argv[2]), std::string(argv[3]));
  }
  if (cmd == "-d") {
    read_compressed_file(std::string(argv[2]), std::string(argv[3]));
  }
}