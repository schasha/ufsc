//! Copyright [2023] <Davi Menegaz Junkes>
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {


template<typename T>
class LinkedQueue {
 public:
    LinkedQueue();

    ~LinkedQueue();

    void clear();  // limpar

    void enqueue(const T& data);  // enfilerar

    T dequeue();  // desenfilerar

    T& front() const;  // primeiro dado

    T& back() const;  // último dado

    bool empty() const;  // fila vazia

    std::size_t size() const;  // tamanho

 private:
    class Node {  // Elemento
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {  // getter: dado
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };

    Node* head{nullptr};  // nodo-cabeça
    Node* tail{nullptr};  // nodo-fim
    std::size_t size_{0};  // tamanho
}; 

template<typename T>
LinkedQueue<T>::LinkedQueue() {}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template<typename T>
void LinkedQueue<T>::clear(){
    while (size_) dequeue();
}

template<typename T>
void LinkedQueue<T>::enqueue(const T& data) {
    if (empty()) {
        tail = new Node(data, nullptr);
        head = tail;
        size_++;
        return;
    }

    Node* new_tail = new Node(data, nullptr); 
    tail->next(new_tail);
    tail = new_tail;
    size_++;
}

template<typename T>
T LinkedQueue<T>::dequeue() {
    if (empty()) throw std::out_of_range("fila vazia");
    
    Node* dequeued = head;
    T dequeued_value = dequeued->data();

    head = head->next();

    delete dequeued;
    size_--;

    return dequeued_value;
}

template<typename T>
T& LinkedQueue<T>::front() const {
    if (empty()) throw std::out_of_range("fila vazia");
    return head->data();
}

template<typename T>
T& LinkedQueue<T>::back() const {
    if (empty()) throw std::out_of_range("fila vazia");
    return tail->data();
}

template<typename T>
bool LinkedQueue<T>::empty() const {
    return !static_cast<bool>(size_);
}

template<typename T>
std::size_t LinkedQueue<T>::size() const {
    return size_;
}


}  // namespace structures

#endif
