#ifndef HUFFMAN_NOH_HPP
#define HUFFMAN_NOH_HPP

#include <stdint.h>
#include <iostream>

using std::ostream;

struct HuffmanNoh{

    uint16_t left{0};
    uint16_t right{0};        

    HuffmanNoh() = default;

    HuffmanNoh(uint16_t left_, uint16_t right_)  {
        left = left_;
        right = right_;
    }
    
    HuffmanNoh(uint16_t leaf_value_)  {
        left = leaf_value_;
    }
};

struct NohHeap{
    uint16_t index;
    int weight;

    NohHeap() = default;

    NohHeap(uint16_t index_, int weight_)  {
        index = index_;
        weight = weight_;
    }

    bool operator>(NohHeap &other){
        return weight > other.weight;
    }

    bool operator<(NohHeap &other){
        return weight < other.weight;
    }

    friend ostream& operator<<(ostream& os, const NohHeap& noh);
};

ostream& operator<<(ostream& os, const NohHeap& noh)
{
    os << noh.index << '-' << noh.weight << '|';
    return os;
}

#endif //HUFFMAN_NOH_HPP