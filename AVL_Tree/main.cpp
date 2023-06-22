#include "tree.hpp"


int main(){
    TreeAVL<int> tree;
    tree.add(3);
    tree.add(4);
    tree.add(6);
    tree.add(8);
    tree.add(2);
    //     tree.add(3);
    // tree.add(4);
    // tree.add(6);
    // tree.add(8);
    // tree.add(2);
    //     tree.add(3);
    // tree.add(4);
    // tree.add(6);
    // tree.add(8);
    // tree.add(2);
    // tree.add(10);


    // tree.print_tree(tree.root_);

    std::cout << std::endl;
    for (auto it = tree.begin(); it != tree.end(); ++it){
        std::cout << it->element_ << "||";
    }

    // std::cout << tree.root_->element_ << std::endl;
    // std::cout << tree.root_->left_n_->element_ << std::endl;
    // std::cout << tree.root_->left_n_->parent_->element_ << std::endl;
    // std::cout << tree.root_->right_n_->element_ << std::endl;
    // std::cout << tree.root_->right_n_->parent_->element_ << std::endl;

    // std::cout << tree.root_->left_n_->left_n_->element_ << std::endl;

    // std::cout << tree.root_->right_n_->right_n_->element_ << std::endl;

    std::cout << "FIND :: " << std::endl;

    auto el2 = tree.find(9);

    std::cout << "el2: end? " << (el2 == tree.end()) << "\n";
    std::cout << "el2: " << el2->element_  << "\n";

    return 0;
}

//https://www.programiz.com/dsa/avl-tree
//https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html