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
                } else
                    left->insert(data_);
            }
            if (data_ > data) {
                if (right == nullptr) {
                    right = new Node(data_);
                } else 
                    right->insert(data_);
            }
        }

        Node* remove(const T& data_) {
            if (left != nullptr && data_ < data)
                left = left->remove(data_);
            if (right != nullptr && data_ > data)
                right = right->remove(data_);

            if (data_ == data) {
                if (left == nullptr && right == nullptr) {
                    delete this;
                    return nullptr;

                } else if (right == nullptr) {
                    return left;
                } else if (left == nullptr) {
                    return right;

                } else {
                    Node* n = right;
                    while (n->left != nullptr)
                        n = n->left;
                    data = n->data;
                    right = right->remove(data);
                }
            }

            return this;
        }

        bool contains(const T& data_) const {
            if (data_ == data)
                return true;

            if (left != nullptr && data_ < data)
                return (left->contains(data_));
            if (right != nullptr && data_ > data)
                return (right->contains(data_));

            return false;
        }

        void pre_order(ArrayList<T>& v) const {
            v.push_back(data);
            if (left != nullptr)
                left->pre_order(v);
            if (right != nullptr)
                right->pre_order(v);
        }
        void in_order(ArrayList<T>& v) const {
            if (left != nullptr)
                left->in_order(v);
            v.push_back(data);
            if (right != nullptr)
                right->in_order(v);
        }

        void post_order(ArrayList<T>& v) const {
            if (left != nullptr)
                left->post_order(v);
            if (right != nullptr)
                right->post_order(v);
            v.push_back(data);
        }
    };

    Node* root{nullptr};
    std::size_t size_{0u};
};

template<typename T>
BinaryTree<T>::~BinaryTree() {
    while (!empty())
        remove(root->data);
}

template<typename T>
void BinaryTree<T>::insert(const T& data) {
    if (empty()) root = new Node(data);
    root->insert(data);
    size_++;
}

template<typename T>
void BinaryTree<T>::remove(const T& data) {
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

