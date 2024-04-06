//! Copyright [2023] <Davi Menegaz Junkes>
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

template<typename T>
class LinkedStack {
public:
    LinkedStack();

    ~LinkedStack();

    void clear(); // limpa pilha

    void push(const T& data); // empilha

    T pop(); // desempilha

    T& top() const; // dado no topo

    bool empty() const; // pilha vazia

    std::size_t size() const; // tamanho da pilha

private:
    class Node {
    public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {  // getter: info
            return data_;
        }
        const T& data() const {  // getter-constante: info
            return data_;
        }

        Node* next() {  // getter: próximo
            return next_;
        }
        const Node* next() const {  // getter-constante: próximo
            return next_;
        }

        void next(Node* next) {  // setter: próximo
            next_ = next;
        }

    private:
        T data_;
        Node* next_;
    };

    Node* top_{nullptr};  // nodo-topo
    std::size_t size_{0};  // tamanho
};

template<typename T>
LinkedStack<T>::LinkedStack() {} 

template<typename T>
LinkedStack<T>::~LinkedStack() {
    clear();
}

template<typename T>
void LinkedStack<T>::clear() {
    while (size_) pop();
}

template<typename T>
void LinkedStack<T>::push(const T& data) {
    if (empty()) {
        top_ = new Node(data, nullptr);
        size_++;
        return;
    }
    top_ = new Node(data, top_);
    size_++;
}

template<typename T>
T LinkedStack<T>::pop() {
    if (empty()) throw std::out_of_range("pilha vazia");

    Node* popped = top_;
    T popped_value = popped->data();

    top_ = top_->next();

    delete popped;
    size_--;

    return popped_value;
}

template<typename T>
T& LinkedStack<T>::top() const {
    if (empty()) throw std::out_of_range("pilha vazia");
    return top_->data();
}

template<typename T>
bool LinkedStack<T>::empty() const {
    return !static_cast<bool>(size_);
}

template<typename T>
std::size_t LinkedStack<T>::size() const {
    return size_;
}

}  // namespace structures

#endif
