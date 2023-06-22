#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <memory>

template <typename T>
struct Node {
    Node() {};     
    Node(T element, 
         std::shared_ptr<Node> left_n,
         std::shared_ptr<Node> right_n, 
         std::shared_ptr<Node> parent) : element_{element},  
                                         left_n_{left_n},
                                         right_n_{right_n},
                                         parent_{parent},
                                         height_{0} {};
    T element_;
    std::shared_ptr<Node> left_n_;
    std::shared_ptr<Node> right_n_;
    std::shared_ptr<Node> parent_;
    int height_;
};

template <typename T>
class TreeAVL;

template <typename T>
class Iterator {

    friend class TreeAVL<T>;

    public:
        Iterator(std::shared_ptr<Node<T>> node, const TreeAVL<T> *tree) : iterator_{node}, tree_{tree} {};

        Node<T>& operator*() const { return *iterator_; }
        Node<T>* operator->() { return iterator_.get(); }
        Iterator& operator++() { 
            if (iterator_->right_n_ != tree_->f_node_) {
                iterator_ = iterator_->right_n_;
                while (iterator_->left_n_ != tree_->f_node_)
                {
                    iterator_ = iterator_->left_n_;
                }
            }

            else if (iterator_->right_n_ == tree_->f_node_) {
                std::shared_ptr<Node<T>> previous = iterator_;
                iterator_ = iterator_->parent_;
                while (previous != iterator_->left_n_ && iterator_ != tree_->f_node_)
                {
                    previous = iterator_;
                    iterator_ = iterator_->parent_;
                }  
            }
            return *this; 
        }  
        Iterator operator++(int) { 
            Iterator tmp = *this; 
            ++(*this); 
            return tmp;
        }

        friend bool operator== (const Iterator& a, const Iterator& b) { return a.iterator_ == b.iterator_; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.iterator_ != b.iterator_; };

    private:
        std::shared_ptr<Node<T>> iterator_;
        const TreeAVL<T>* tree_;
};

template <typename T>
class TreeAVL {

    friend class Iterator<T>;

    public:
        TreeAVL();
        Iterator<T> begin();
        Iterator<T> end();
        Iterator<T> find(T element);
        Iterator<T> add(T element);
        Iterator<T> remove(T element);
        void print_tree(Node<T> *n);

        std::shared_ptr<Node<T>> root_;
    private:
        void LeftRotate(std::shared_ptr<Node<T>> x, std::shared_ptr<Node<T>> y);
        void RightRotate(std::shared_ptr<Node<T>> x, std::shared_ptr<Node<T>> y);
        void LeftRight(std::shared_ptr<Node<T>> x, std::shared_ptr<Node<T>> y, std::shared_ptr<Node<T>> z);
        void RightLeft(std::shared_ptr<Node<T>> x, std::shared_ptr<Node<T>> y, std::shared_ptr<Node<T>> z);

        std::shared_ptr<Node<T>> InsertElement(std::shared_ptr<Node<T>> curr_node, std::shared_ptr<Node<T>> new_node);
        std::shared_ptr<Node<T>> SearchElement(std::shared_ptr<Node<T>> curr_node, T element);
        std::shared_ptr<Node<T>> f_node_;
};

template <typename T>
TreeAVL<T>::TreeAVL() : f_node_{std::make_shared<Node<T>>()}{
    f_node_->left_n_ = f_node_;
    f_node_->right_n_ = f_node_;
    f_node_->parent_ = root_;
    f_node_->height_ = 0;
    root_ = f_node_;
};

template <typename T>
Iterator<T> TreeAVL<T>::begin(){
    std::shared_ptr<Node<T>> smallest = root_;
    while (smallest->left_n_ != f_node_)
    {
      smallest = smallest->left_n_;
    }
    return Iterator<T>(smallest, this);
};

template <typename T>
Iterator<T> TreeAVL<T>::end(){
   return Iterator<T>(f_node_, this);
};

template <typename T>
Iterator<T> TreeAVL<T>::find(T element){
   return Iterator<T>(SearchElement(root_, element), this);
};

template <typename T>
Iterator<T> TreeAVL<T>::add(T element){
   std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(element, f_node_, f_node_, f_node_);
   root_ = InsertElement(root_, new_node);
   return Iterator<T>(new_node, this);
};

template <typename T>
Iterator<T> TreeAVL<T>::remove(T element){
   return Iterator<T>(f_node_, this);
};

template <typename T>
void TreeAVL<T>::print_tree(Node<T>* n){
   if (n != f_node_) {
    print_tree(n->left_n_);
    std::cout << n->element_ <<  "|";
    print_tree(n->right_n_);
   }
};

template <typename T>
void TreeAVL<T>::LeftRotate(std::shared_ptr<Node<T>> x, std::shared_ptr<Node<T>> y){

    x->right_n_ = y->left_n_;
    y->left_n_->parent_ = x;

    y->parent_ = x->parent_;
    if (x->parent_ == f_node_) {
        root_ = y;
    }
    else if (x->parent_->left_n_ == x){
        x->parent_->left_n_ = y;
    }
    else if (x->parent_->right_n_ == x){ 
        x->parent_->right_n_ = y;
    }
    x->parent_ = y;
    y->left_n_ = x;   
}

template <typename T>
void TreeAVL<T>::RightRotate(std::shared_ptr<Node<T>> x, std::shared_ptr<Node<T>> y){
    y->left_n_ = x->right_n_;
    x->right_n_->parent_ = y;

    x->parent_ = y->parent_;
    if (y->parent_ == f_node_) {
        root_ = x;
    }
    else if (y->parent_->right_n_ == y){
        y->parent_->right_n_ = x;
    }
    else if (y->parent_->left_n_ == y){
        y->parent_->left_n_ = x;
    }
    y->parent_ = x;
    x->right_n_ = y;
}

template <typename T>
void TreeAVL<T>::LeftRight(std::shared_ptr<Node<T>> x, std::shared_ptr<Node<T>> y, std::shared_ptr<Node<T>> z){
    LeftRotate(x, y);
    RightRotate(y, z);
}

template <typename T>
void TreeAVL<T>::RightLeft(std::shared_ptr<Node<T>> x, std::shared_ptr<Node<T>> y, std::shared_ptr<Node<T>> z){
    RightRotate(x, y);
    LeftRotate(z, y);
}
template <typename T>
std::shared_ptr<Node<T>> TreeAVL<T>::InsertElement(std::shared_ptr<Node<T>> curr_node, std::shared_ptr<Node<T>> new_node){
    if (curr_node == f_node_) {
        return new_node;
    }
    if (new_node->element_ < curr_node->element_) {
        curr_node->left_n_ = InsertElement(curr_node->left_n_, new_node);
        curr_node->left_n_->parent_ =  curr_node;
    }
    else if(new_node->element_ >= curr_node->element_){
        curr_node->right_n_ = InsertElement(curr_node->right_n_, new_node);
        curr_node->right_n_->parent_ = curr_node;
    }

    curr_node->height_ = 1 + std::max(curr_node->left_n_->height_, curr_node->right_n_->height_);
    int balance_factor = curr_node->left_n_->height_ - curr_node->right_n_->height_;

    std::shared_ptr<Node<T>> ret_node = curr_node;

    if (balance_factor > 1) {
        if (new_node->element_ < curr_node->left_n_->element_) {
            ret_node = curr_node->left_n_;
            RightRotate(curr_node->left_n_, curr_node);
        }
        if (new_node->element_ >= curr_node->left_n_->element_){
            ret_node = curr_node->left_n_->right_n_;
            LeftRight(curr_node->left_n_, curr_node->left_n_->right_n_, curr_node);
        }
    }

    if (balance_factor < -1) {
        if (new_node->element_ >= curr_node->right_n_->element_) {
            ret_node = curr_node->right_n_;
            LeftRotate(curr_node, curr_node->right_n_);
        }
        if (new_node->element_ < curr_node->right_n_->element_) {
            ret_node = curr_node->right_n_->left_n_;
            RightLeft(curr_node->right_n_->left_n_, curr_node->right_n_, curr_node);
        }
    }

    return ret_node;
}

template <typename T>
std::shared_ptr<Node<T>> TreeAVL<T>::SearchElement(std::shared_ptr<Node<T>> curr_node, T element){
    if (curr_node == f_node_){
        return curr_node;
    }

    std::shared_ptr<Node<T>> next_search_root = nullptr;
    if (curr_node->element_ > element) {
        next_search_root = curr_node->left_n_;
    }
    else if (curr_node->element_ < element) {
        next_search_root = curr_node->right_n_;
    }

    if (next_search_root == nullptr){
        return curr_node;
    }

    return SearchElement(next_search_root, element);
}

#endif //TREE_HPP