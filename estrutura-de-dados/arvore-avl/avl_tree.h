//! Copyright [2023] <Davi Menegaz Junkes>
#ifndef STRUCTURES_AVL_TREE_H
#define STRUCTURES_AVL_TREE_H

#include <algorithm>
#include <stdexcept>
#include "array_list.h"


namespace structures {

template<typename T>
class AVLTree {
 public:
    ~AVLTree();

    void insert(const T& data);
    void remove(const T& data);

    bool contains(const T& data) const;
    bool empty() const;
    std::size_t size() const;
    int height() const;

    ArrayList<T> pre_order() const;
    ArrayList<T> in_order() const;
    ArrayList<T> post_order() const;

    T root_val();

 private:
    struct Node {
        explicit Node(const T& data_) {
            data = data_;
        }

        T data;
        int height_{0u};
        Node* left{nullptr};
        Node* right{nullptr};

        int height() {
            if (this)
                return height_;
            return -1;
        }

        Node* insert(const T& data_) {
            if (not this)
                return new Node(data_);

            if (data_ < data)
                left = left->insert(data_);
            else if (data_ > data)
                right = right->insert(data_);
            else
                return this;

            updateHeight();

            // balancing
            int balance = getBalance();

            // rotate right
            if (balance > 1) {
                if (data_ < left->data)
                    return simpleRight();
                else if (data_ > left->data) {
                    left = left->simpleLeft();
                    return simpleRight();
                }
            }

            // rotate left
            if (balance < -1) {
                if (data_ > right->data)
                    return simpleLeft();
                else if (data_ < right->data) {
                    right = right->simpleRight();
                    return simpleLeft();
                }
            }

            return this;
        }

        Node* remove(const T& data_) {
            if (not this)
                return this;

            if (data_ < data )
                left = left->remove(data_);
            else if (data_> data )
                right = right->remove(data_);
            else {
                if (left == nullptr && right == nullptr) {
                    delete this;
                    return nullptr;

                } else if (right == nullptr) {
                    Node* n = left;
                    delete this;
                    return n;
                } else if (left == nullptr) {
                    Node* n = right;
                    delete this;
                    return n;

                } else {
                    Node* n = right;
                    while (n->left != nullptr)
                        n = n->left;
                    data = n->data;
                    right = right->remove(data);
                }
            }

            if (not this)
                return this;

            updateHeight();

            // balancing
            int balance = getBalance();

            // rotate right
            if (balance > 1) {
                if (left->getBalance() >= 0)
                    return simpleRight();
                else if (left->getBalance() < 0) {
                    left = left->simpleLeft();
                    return simpleRight();
                }
            }

            // rotate left
            if (balance < -1) {
                if (right->getBalance() <= 0)
                    return simpleLeft();
                else if (right->getBalance() > 0) {
                    right = right->simpleRight();
                    return simpleLeft();
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

        void updateHeight() {
            height_ = std::max(left->height(), right->height()) + 1;
        }

        int getBalance() {
            return left->height() - right->height();
        }

        Node* simpleLeft() {
            Node* node_aux;

            node_aux = right;
            right = node_aux->left;
            node_aux->left = this;

            this->updateHeight();
            node_aux->updateHeight();

            return node_aux;
        }

        Node* simpleRight() {
            Node* node_aux;

            node_aux = left;
            left = node_aux->right;
            node_aux->right = this;

            this->updateHeight();
            node_aux->updateHeight();

            return node_aux;
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
AVLTree<T>::~AVLTree() {
    while (!empty()) remove(root->data);
}

template<typename T>
void AVLTree<T>::insert(const T& data) {
    if (empty()) root = new Node(data);
    else root = root->insert(data);
    size_++;
}

template<typename T>
void AVLTree<T>::remove(const T& data) {
    if (empty()) throw std::out_of_range("lista vazia");
    root = root->remove(data);
    size_--;
}

template<typename T>
bool AVLTree<T>::contains(const T& data) const {
    if (empty()) throw std::out_of_range("lista vazia");
    return root->contains(data);
}

template<typename T>
bool AVLTree<T>::empty() const {
    return !static_cast<bool>(size_);
}

template<typename T>
std::size_t AVLTree<T>::size() const {
    return size_;
}

template<typename T>
int AVLTree<T>::height() const {
    return root->height();
}

template<typename T>
ArrayList<T> AVLTree<T>::pre_order() const {
    ArrayList<T> data = ArrayList<T>(size_);
    root->pre_order(data);
    return data;
}

template<typename T>
ArrayList<T> AVLTree<T>::in_order() const {
    ArrayList<T> data = ArrayList<T>(size_);
    root->in_order(data);
    return data;
}

template<typename T>
ArrayList<T> AVLTree<T>::post_order() const {
    ArrayList<T> data = ArrayList<T>(size_);
    root->post_order(data);
    return data;
}

}  // namespace structures

#endif

