//! Copyright [2023] <Davi Menegaz Junkes>
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>


namespace structures {

//! ...
template<typename T>
class LinkedList {
 public:
    //! ...
    LinkedList();  // construtor padrão
    //! ...
    ~LinkedList();  // destrutor
    //! ...
    void clear();  // limpar lista
    //! ...
    void push_back(const T& data);  // inserir no fim
    //! ...
    void push_front(const T& data);  // inserir no início
    //! ...
    void insert(const T& data, std::size_t index);  // inserir na posição
    //! ...
    void insert_sorted(const T& data);  // inserir em ordem
    //! ...
    T& at(std::size_t index);  // acessar um elemento na posição index
    //! ...
    T pop(std::size_t index);  // retirar da posição
    //! ...
    T pop_back();  // retirar do fim
    //! ...
    T pop_front();  // retirar do início
    //! ...
    void remove(const T& data);  // remover específico
    //! ...
    bool empty() const;  // lista vazia
    //! ...
    bool contains(const T& data) const;  // contém
    //! ...
    std::size_t find(const T& data) const;  // posição do dado
    //! ...
    std::size_t size() const;  // tamanho da lista

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

    Node* end() {  // último nodo da lista
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }

    Node* head{nullptr};
    std::size_t size_{0u};
};

template<typename T>
LinkedList<T>::LinkedList() {

}

template<typename T>
LinkedList<T>::~LinkedList() {

}

template<typename T>
void LinkedList<T>::clear() {

}

template<typename T>
void LinkedList<T>::push_back(const T& data) {

}

template<typename T>
void LinkedList<T>::push_front(const T& data) {

}

template<typename T>
void LinkedList<T>::insert(const T& data, std::size_t index) {

}

template<typename T>
void LinkedList<T>::insert_sorted(const T& data) {

}

template<typename T>
T& LinkedList<T>::at(std::size_t index) {

}

template<typename T>
T LinkedList<T>::pop(std::size_t index) {

}

template<typename T>
T LinkedList<T>::pop_back() {

}

template<typename T>
T LinkedList<T>::pop_front() {

}

template<typename T>
void LinkedList<T>::remove(const T& data) {

}

template<typename T>
bool LinkedList<T>::empty() const {

}

template<typename T>
bool LinkedList<T>::contains(const T& data) const {

}

template<typename T>
std::size_t LinkedList<T>::find(const T& data) const {

}

template<typename T>
std::size_t LinkedList<T>::size() const {

}

}  // namespace structures

#endif

