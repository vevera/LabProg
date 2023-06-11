#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

template <typename T>
struct Node {
    T element_;
    Node* left_n_;
    Node* right_n_;
    Node* parent_;
    int height_;
};

template <typename T>
class TreeAVL;

template <typename T>
class Iterator {
    public:
        Iterator(const Node<T>* node, const TreeAVL<T> *tree) : iterator_{node}, tree_{tree} {};

        Node<T>& operator*() const { return *iterator_; }
        Node<T>* operator->() { return iterator_; }
        Iterator& operator++() { 
            //iterator_++; 
            return *this; 
        }  
        Iterator operator++(int) { 
            // Iterator tmp = *this; 
            // ++(*this); 
            // return tmp;
            return *this;
        }

        friend bool operator== (const Iterator& a, const Iterator& b) { return a.iterator_ == b.iterator_; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.iterator_ != b.iterator_; };

    private:
        friend class TreeAVL<T>;

        const Node<T>* iterator_;
        const TreeAVL<T>* tree_;
};

template <typename T>
class TreeAVL {

    public:
        TreeAVL();
        Iterator<T> begin();
        Iterator<T> end();
        Iterator<T> find(T element);
        Iterator<T> add(T element);
        Iterator<T> remove(T element);
        void print_tree(Node<T> *n);

        Node<T> *root_;
    private:
        void LeftRotate(Node<T> *x, Node<T> * y);
        void RightRotate(Node<T> *x, Node<T> * y);
        void LeftRight(Node<T> *x, Node<T> * y, Node<T> * z);
        void RightLeft(Node<T> *x, Node<T> * y, Node<T> * z);

        Node<T> * InsertElement(Node<T> *curr_node, T element);
        Node<T> *f_node_;
};

template <typename T>
TreeAVL<T>::TreeAVL() : f_node_{new Node<T>}{
    // root_->left_n_ = f_node_;
    // root_->right_n_ = f_node_;
    // root_->parent_ = f_node_;
    // root_->height_  = 1;
    f_node_->left_n_ = f_node_;
    f_node_->right_n_ = f_node_;
    f_node_->parent_ = root_;
    f_node_->height_ = 0;

    root_ = f_node_;
};

template <typename T>
Iterator<T> TreeAVL<T>::begin(){
    return Iterator<T>(root_, this);
};

template <typename T>
Iterator<T> TreeAVL<T>::end(){
   return Iterator<T>(f_node_, this);
};

template <typename T>
Iterator<T> TreeAVL<T>::find(T element){
   return Iterator<T>(f_node_, this);
};

template <typename T>
Iterator<T> TreeAVL<T>::add(T element){
   root_ = InsertElement(root_, element);
   return Iterator<T>(f_node_, this);
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
void TreeAVL<T>::LeftRotate(Node<T> *x, Node<T> * y){

    x->right_n_ = y->left_n_;
    y->left_n_->parent_ == x;

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
void TreeAVL<T>::RightRotate(Node<T> *x, Node<T> * y){
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
void TreeAVL<T>::LeftRight(Node<T> *x, Node<T> * y, Node<T> * z){
    LeftRotate(x, y);
    RightRotate(y, z);
}

template <typename T>
void TreeAVL<T>::RightLeft(Node<T> *x, Node<T> * y, Node<T> * z){
    RightRotate(x, y);
    LeftRotate(z, y);
}
template <typename T>
Node<T>* TreeAVL<T>::InsertElement(Node<T> *curr_node, T element){
    if (curr_node == f_node_) {
        return new Node<T>{element, f_node_, f_node_, curr_node, 1};
    }
    if (element < curr_node->element_) {
        curr_node->left_n_ = InsertElement(curr_node->left_n_, element);
    }
    else if(element >= curr_node->element_){
        curr_node->right_n_ = InsertElement(curr_node->right_n_, element);
    }

    curr_node->height_ = 1  + std::max(curr_node->left_n_->height_, curr_node->right_n_->height_);
    int balance_factor = curr_node->left_n_->height_ - curr_node->right_n_->height_;

    Node<T> * ret_node = curr_node;

    if (balance_factor > 1) {
        std::cout << "iterate 1" << element << std::endl;
        if (element < curr_node->left_n_->element_) {
            ret_node = curr_node->left_n_;
            RightRotate(curr_node->left_n_, curr_node);
        }
        if (element >= curr_node->left_n_->element_){
            ret_node = curr_node->left_n_->right_n_;
            LeftRight(curr_node->left_n_, curr_node->left_n_->right_n_, curr_node);
        }
    }

    if (balance_factor < -1) {
        std::cout << "iterate -1 " << element << std::endl;
        if (element >= curr_node->right_n_->element_) {
            ret_node = curr_node->right_n_;
            LeftRotate(curr_node, curr_node->right_n_);
        }
        if (element < curr_node->right_n_->element_) {
            ret_node = curr_node->right_n_->left_n_;
            RightLeft(curr_node->right_n_->left_n_, curr_node->right_n_, curr_node);
        }
    }

    return ret_node;
}

#endif //TREE_HPP