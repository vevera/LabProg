#ifndef SWAP_HPP
#define SWAP_HPP

template <typename T>
void swap(T& a, T& b){
    T aux = a;
    a = b;
    b = aux;
}

#endif