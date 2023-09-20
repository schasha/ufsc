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
LinkedList<T>::LinkedList(){}

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
void LinkedList<T>::clear() {
    while (size() > 0) {
        pop_front();
    }
}

template<typename T>
void LinkedList<T>::push_back(const T& data) {
    Node* tail = end();
    Node* new_tail = new Node(data, nullptr);
    tail->next(new_tail);
    size_++;
}

template<typename T>
void LinkedList<T>::push_front(const T& data) {
   Node* new_first = new Node(data, head->next());
   head->next(new_first);
   size_++;
}

template<typename T>
void LinkedList<T>::insert(const T& data, std::size_t index) {
    Node* it = head->next(); //next pos
    Node* previous;

    if (index) {
        for (int i = 0; i < index; i++) {
            previous = it;
            it = it->next();
        }
        Node* new_node = new Node(data, it);
        previous->next(new_node);
        size_ ++;
    }

    if (!index) {
        push_front(data);
    }
}

template<typename T>
void LinkedList<T>::insert_sorted(const T& data) {
    if (empty()) push_front(data);

    if (!empty()) {
        bool maior = false;
        std::size_t index;
        Node* it = head->next();

        for (int i = 0; i < static_cast<int>(size_); i++) {
            if (it->data() >= data) {
                index = i;
                maior = true;
                break;
            }
            it = it->next();
        }

        if (maior) {
            insert(data, index);
        }
        if (!maior) {
            push_back(data);
        }
    }
}

template<typename T>
T& LinkedList<T>::at(std::size_t index) {
    Node* it = head->next();
    for (int i = 0; i < index; i++) {
        it = it->next();
    }
    return it->data();
}

template<typename T>
T LinkedList<T>::pop(std::size_t index) {
    Node* popped = head->next();
    Node* previous;
    T popped_value;

    if (index) {
        for (int i = 0; i < index; i++) {
            previous = popped;
            popped = popped->next();
        }
        popped_value = popped->data();
        previous->next(popped->next());
        delete popped;
        size_ --;
    }

    if (!index) {
        popped_value = pop_front();
    }
    return popped_value;
}

template<typename T>
T LinkedList<T>::pop_back() {
    Node* new_end;
    Node* popped = head->next();
    for (int i = 0; i < size(); i++) {
        new_end = popped;
        popped = popped->next();
    }

    new_end->next(nullptr);

    T popped_value = popped->data();
    delete popped;
    size_--;

    return popped_value;
}

template<typename T>
T LinkedList<T>::pop_front() {
    Node* popped = head->next();
    head->next(popped->next());

    T popped_value = popped->data();
    delete popped;
    size_--;

    return popped_value;
}

template<typename T>
void LinkedList<T>::remove(const T& data) {
    Node* it = head->next();
    Node* previous;

    for (int i = 0; i < size(); i++) {
        if (data == it->data()) {
            previous->next(it->next());
            delete it;
            break;
        }
        previous = it;
        it = it->next();
    }
    size_ --;
}

template<typename T>
bool LinkedList<T>::empty() const {
    return !bool(size_);
}

template<typename T>
bool LinkedList<T>::contains(const T& data) const {
    Node* it = head->next();
    for (int i = 0; i < size(); i++) {
        if (it->data() == data) return true;
        it = it->next();
    }
    return false;
}

template<typename T>
std::size_t LinkedList<T>::find(const T& data) const {
    Node* it = head->next();
    for (int i = 0; i < size(); i++) {
        if (it->data() == data) return i;
        it = it->next();
    }
    return(size());
}

template<typename T>
std::size_t LinkedList<T>::size() const {
    return size_;
}

}  // namespace structures

#endif

