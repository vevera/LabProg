#ifndef MY_RANDOM_GEN
#define MY_RANDOM_GEN

#include <cstddef>
#include <random>
#include <iostream>

class MyRandomGen{

    public:
        MyRandomGen(): generator{r_disp()} {};
        
        int generate (){
            if (distr == nullptr) {
                std::cout << "Distr null\n"; 
                return -1;
            }

            std::uniform_int_distribution<int> int_distr = *distr;

            return int_distr(generator);
        }

        void change_interval(int start, int end){
            distr = new std::uniform_int_distribution<int>(start, end);
        }

        static MyRandomGen * instance(){
            if (instance_ == nullptr) {
                instance_ = new MyRandomGen();
            }
            return instance_;
        }

    private:
        std::random_device r_disp;
        std::mt19937 generator;
        std::uniform_int_distribution<int> *distr = nullptr;
        static MyRandomGen *instance_;
        
};

MyRandomGen* MyRandomGen::instance_ = nullptr;

#endif