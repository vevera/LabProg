#include "tree.hpp"


int main(){
    TreeAVL<int> tree;
    tree.add(3);
    tree.add(4);
    tree.add(6);
    tree.add(8);
    tree.add(2);
        tree.add(3);
    tree.add(4);
    tree.add(6);
    tree.add(8);
    tree.add(2);
        tree.add(3);
    tree.add(4);
    tree.add(6);
    tree.add(8);
    tree.add(2);
    tree.add(10);

    tree.print_tree(tree.root_);
    // std::cout << tree.root_->element_ << std::endl;
    // std::cout << tree.root_->left_n_->element_ << std::endl;
    // std::cout << tree.root_->right_n_->element_ << std::endl;

    // std::cout << tree.root_->left_n_->left_n_->element_ << std::endl;

    // std::cout << tree.root_->right_n_->right_n_->element_ << std::endl;
    return 0;
}