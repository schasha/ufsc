//! Copyright [2023] <Davi Menegaz Junkes>
#ifndef STRUCTURES_BINARY_TREE_H
#define STRUCTURES_BINARY_TREE_H

#include <cstdint>
#include <stdexcept>
#include "array_list.h"

namespace structures {

template<typename T>
class BinaryTree {
 public:
    ~BinaryTree();

    void insert(const T& data);
    void remove(const T& data);

    bool contains(const T& data) const;
    bool empty() const;
    std::size_t size() const;

    ArrayList<T> pre_order() const;
    ArrayList<T> in_order() const;
    ArrayList<T> post_order() const;

 private:
    struct Node {
        Node(const T& data_) {
            data = data_;
        }

        T data;
        Node* left{nullptr};
        Node* right{nullptr};

        void insert(const T& data_) {
            if (data_ < data) {
                if (left == nullptr) {
                    left = new Node(data_);
                } else {
                    left->insert(data_);
                }
            }
            if (data_ > data) {
                if (right == nullptr) {
                    right = new Node(data_);
                } else {
                    right->insert(data_);
                }
            }
        }
        bool remove(const T& data_) {
            if (data_ == data) {
                return true;
            }
            if (data_ < data) {
                if (left->remove(data_)) {
                    delete left;
                    left = nullptr;
                }
            }
            if (data_ > data) {
                if (right->remove(data_)) {
                    delete right;
                    right = nullptr;
                }
            }
            return false;
        }

        bool contains(const T& data_) const {
            if (data_ == data) {
                return true;
            }
            if (data_ < data) {
                if (left->contains(data_)) {
                    return true;
                }
            }
            if (data_ > data) {
                if (right->contains(data_)) {
                    return true;
                }
            }
            return false;
        }

        void pre_order(ArrayList<T>& v) const {
            v.push_back(data);
            left->pre_order(v);
            right->pre_order(v);
        }
        void in_order(ArrayList<T>& v) const {
            left->in_order(v);
            v.push_back(data);
            right->in_order(v);
        }

        void post_order(ArrayList<T>& v) const {
            left->post_order(v);
            right->post_order(v);
            v.push_back(data);
        }
    };

    Node* root{nullptr};
    std::size_t size_{0u};
};

template<typename T>
BinaryTree<T>::~BinaryTree() {
}

template<typename T>
void BinaryTree<T>::insert(const T& data) {
    if (empty()) root = new Node(data);
    root->insert(data);
    size_++;
}

template<typename T>
void BinaryTree<T>::remove(const T& data) { // errado
    if (empty()) throw std::out_of_range("lista vazia");
    root->remove(data);
    size_--;
}

template<typename T>
bool BinaryTree<T>::contains(const T& data) const {
    if (empty()) throw std::out_of_range("lista vazia");
    return root->contains(data);
}

template<typename T>
bool BinaryTree<T>::empty() const {
    return !static_cast<bool>(size_);
}

template<typename T>
std::size_t BinaryTree<T>::size() const {
    return size_;
}

template<typename T>
ArrayList<T> BinaryTree<T>::pre_order() const {
    ArrayList<T>* data = new ArrayList<T>(size_);
    root->pre_order(*data);    
    return *data;
}

template<typename T>
ArrayList<T> BinaryTree<T>::in_order() const {
    ArrayList<T>* data = new ArrayList<T>(size_);
    root->in_order(*data);    
    return *data;
}

template<typename T>
ArrayList<T> BinaryTree<T>::post_order() const {
    ArrayList<T>* data = new ArrayList<T>(size_);
    root->post_order(*data);    
    return *data;
}

} //  namespace structures

#endif

