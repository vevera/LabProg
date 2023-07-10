#include "solucao.hpp"

#include <string>
#include <vector>
#include <utility> 

int main(){

    DicioAVL<float, float> dict;
    // {

    //     DicioAVL<float, std::string> dict;
    //     dict.inserir(3, "ola");
    //     dict.inserir(4, "mundo");
    //     dict.inserir(3.5, "meu");

    //     for (auto p : dict){
    //         std::cout << p->chave << " | " << p->valor << std::endl;
    //     }

    //     auto find = dict.buscar(3.5);

    //     dict.remover(find);

    //     for (auto p : dict){
    //         std::cout << p->chave << " | " << p->valor << std::endl;
    //     }

    //     std::cout << find->chave << std::endl;
    // }
    
    // {
    //     auto it1 = dict.inserir(204, -21);
    //     auto it2 = dict.inserir(169.75, 59.5);
    //     auto it3 = dict.inserir(246.75, -60);
    //     std::cout << "it3->chave " << it3->chave << "it3->valor " << it3->valor
    //                << "\nit3->filho_dir_->chave " << it3->filho_dir_->chave  
    //                << "\nit3->filho_esq_->chave " << it3->filho_esq_->chave 
    //                << std::endl;
    //     std::cout << "is sent? " << (it3->filho_dir_ == &dict.sent) << std::endl;
    //     auto it4 = dict.inserir(-98.75, 53.5);
    //     auto it5 = dict.inserir(-133.25, 10.5);
    //     auto it6 = dict.inserir(-13.5, 25.5);

    //     std::cout << "dict.raiz val: " << dict.raiz->valor << "\n";
    //     std::cout << "dict.raiz esq esq chave: " << dict.raiz->filho_esq_->filho_esq_->chave << "\n";

    //     for (auto p : dict){
    //         std::cout << p->chave << " | " << p->valor << std::endl;
    //     }

    //     auto b1 = dict.buscar(204);
    //     auto b2 = dict.buscar(169.75);
    //     auto b3 = dict.buscar(246.75);
    //     auto b4 = dict.buscar(-98.75);
    //     auto b5 = dict.buscar(-133.25);
    //     auto b6 = dict.buscar(-13.5);

    //     std::cout << "\nb1 == it1? " << (b1 == it1)  << "b1 chave: " << b1.chave() << "b1 val: " << b1.valor() << "\n";
    //     std::cout << "b2 == it2? " << (b2 == it2)  << "b2 chave: " << b2.chave() << "b2 val: " << b2.valor() << "\n";
    //     std::cout << "b3 == it3? " << (b3 == it3)  << "b3 chave: " << b3.chave() << "b3 val: " << b3.valor() << "\n";
    //     std::cout << "b4 == it4? " << (b4 == it4)  << "b4 chave: " << b4.chave() << "b4 val: " << b4.valor() << "\n";
    //     std::cout << "b5 == it5? " << (b5 == it5)  << "b5 chave: " << b5.chave() << "b5 val: " << b5.valor() << "\n";
    //     std::cout << "b6 == it6? " << (b6 == it6)  << "b6 chave: " << b6.chave() << "b6 val: " << b6.valor() << "\n";

    //     dict.remover(b6);

    //     std::cout << "dict.raiz KEY: " << dict.raiz->chave << "dict.raiz FD KEY: " << dict.raiz->filho_dir_->chave << "\n";

    //     b1 = dict.buscar(204);
    //     b2 = dict.buscar(169.75);
    //     b3 = dict.buscar(246.75);
    //     b4 = dict.buscar(-98.75);
    //     b5 = dict.buscar(-133.25);
    //     b6 = dict.buscar(-13.5);

    //     std::cout << "\nb1 == it1? " << (b1 == it1)  << "b1 chave: " << b1.chave() << "b1 val: " << b1.valor() << "\n";
    //     std::cout << "b2 == it2? " << (b2 == it2)  << "b2 chave: " << b2.chave() << "b2 val: " << b2.valor() << "\n";
    //     std::cout << "b3 == it3? " << (b3 == it3)  << "b3 chave: " << b3.chave() << "b3 val: " << b3.valor() << "\n";
    //     std::cout << "b4 == it4? " << (b4 == it4)  << "b4 chave: " << b4.chave() << "b4 val: " << b4.valor() << "\n";
    //     std::cout << "b5 == it5? " << (b5 == it5)  << "b5 chave: " << b5.chave() << "b5 val: " << b5.valor() << "\n";
    //     std::cout << "b6 == it6? " << (b6 == it6)  << "b6 chave: " << b6.chave() << "b6 val: " << b6.valor() << "\n";

    //     dict.remover(b1);

    //     std::cout << "dict.raiz KEY: " << dict.raiz->chave << "dict.raiz FD KEY: " << dict.raiz->filho_dir_->chave << "\n";


    //     b1 = dict.buscar(204);
    //     b2 = dict.buscar(169.75);
    //     b3 = dict.buscar(246.75);
    //     b4 = dict.buscar(-98.75);
    //     b5 = dict.buscar(-133.25);
    //     b6 = dict.buscar(-13.5);

    //     std::cout << "\nb1 == it1? " << (b1 == it1)  << "b1 chave: " << b1.chave() << "b1 val: " << b1.valor() << "\n";
    //     std::cout << "b2 == it2? " << (b2 == it2)  << "b2 chave: " << b2.chave() << "b2 val: " << b2.valor() << "\n";
    //     std::cout << "b3 == it3? " << (b3 == it3)  << "b3 chave: " << b3.chave() << "b3 val: " << b3.valor() << "\n";
    //     std::cout << "b4 == it4? " << (b4 == it4)  << "b4 chave: " << b4.chave() << "b4 val: " << b4.valor() << "\n";
    //     std::cout << "b5 == it5? " << (b5 == it5)  << "b5 chave: " << b5.chave() << "b5 val: " << b5.valor() << "\n";
    //     std::cout << "b6 == it6? " << (b6 == it6)  << "b6 chave: " << b6.chave() << "b6 val: " << b6.valor() << "\n";

    //     dict.remover(b2);

    //     std::cout << "dict.raiz KEY: " << dict.raiz->chave << "dict.raiz FD KEY: " << dict.raiz->filho_dir_->chave << "\n";


    //     b1 = dict.buscar(204);
    //     b2 = dict.buscar(169.75);
    //     b3 = dict.buscar(246.75);
    //     b4 = dict.buscar(-98.75);
    //     b5 = dict.buscar(-133.25);
    //     b6 = dict.buscar(-13.5);

    //     std::cout << "\nb1 == it1? " << (b1 == it1)  << "b1 chave: " << b1.chave() << "b1 val: " << b1.valor() << "\n";
    //     std::cout << "b2 == it2? " << (b2 == it2)  << "b2 chave: " << b2.chave() << "b2 val: " << b2.valor() << "\n";
    //     std::cout << "b3 == it3? " << (b3 == it3)  << "b3 chave: " << b3.chave() << "b3 val: " << b3.valor() << "\n";
    //     std::cout << "b4 == it4? " << (b4 == it4)  << "b4 chave: " << b4.chave() << "b4 val: " << b4.valor() << "\n";
    //     std::cout << "b5 == it5? " << (b5 == it5)  << "b5 chave: " << b5.chave() << "b5 val: " << b5.valor() << "\n";
    //     std::cout << "b6 == it6? " << (b6 == it6)  << "b6 chave: " << b6.chave() << "b6 val: " << b6.valor() << "\n";


        

    //     // for (auto p : *dict){
    //     //     std::cout << p.chave << " | " << p.valor << std::endl;
    //     // }

    //     // std::cout << b1.chave << std::endl;
    //     // delete dict;
    //     // auto see_heights = [](auto* noh){
    //     //     std::cout << "\naltura: " << noh->altura_  << "\n";
    //     //     std::cout  << noh->valor << " : " << noh->chave;
    //     // };
    //     // dict.ApplyFunctionToElements(dict.raiz, see_heights);
    // }


    std::vector<std::pair<float, float>> elements =  {{-81, 2.5},{271.25, 83},{81.25, 43}};
    std::vector<std::pair<float, float>> elements2 =  {{204, -21},{169.75, 59.5},{246.75, -60},{-98.75, 53.5},
                                                        {-133.25, 10.5},{-13.5, 25.5},{-81, 2.5},{271.25, 83}};
    std::vector<DicioAVL<float, float>::Iterador> iteradores;

    for (auto& pair : elements2)  {
        auto it = dict.inserir(pair.first, pair.second);
        iteradores.emplace_back(it);
    }


    auto see_heights = [](auto* noh) {
        std::cout << "NOH: " << "k>  " << noh->chave << " v>  " << noh->valor << "\n";
        std::cout << "\naltura: " << noh->altura_  << "\n";
    };
    dict.ApplyFunctionToElements(dict.raiz, see_heights);

    return 0;
}