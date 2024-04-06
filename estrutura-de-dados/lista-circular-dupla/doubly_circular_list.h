//! Copyright [2023] <Davi Menegaz Junkes>
#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

template<typename T>
class DoublyCircularList {
 public:
    DoublyCircularList();
    ~DoublyCircularList();

    void clear();

    void push_back(const T& data);  // insere no fim
    void push_front(const T& data);  // insere no início
    void insert(const T& data, std::size_t index);  // insere na posição
    void insert_sorted(const T& data);  // insere em ordem

    T pop(std::size_t index);  // retira da posição
    T pop_back();  // retira do fim
    T pop_front();  // retira do início
    void remove(const T& data);  // retira específico

    bool empty() const;  // lista vazia
    bool contains(const T& data) const;  // contém

    T& at(std::size_t index);  // acesso a um elemento (checando limites)
    const T& at(std::size_t index) const;  // getter constante a um elemento

    std::size_t find(const T& data) const;  // posição de um dado
    std::size_t size() const;  // tamanho

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
        Node(const T& data, Node* prev, Node* next):
            data_{data},
            prev_{prev},
            next_{next}
        {}

        T& data() {
            return data_;
        }
        const T& data() const {
            return data_;
        }

        Node* prev() {
            return prev_;
        }
        const Node* prev() const {
            return prev_;
        }

        void prev(Node* node) {
            prev_ = node;
        }

        Node* next() {
            return next_;
        }
        const Node* next() const {
            return next_;
        }

        void next(Node* node) {
            next_ = node;
        }

     private:
        T data_;
        Node* prev_{nullptr};
        Node* next_{nullptr};
    };

    Node* sentinel;
    std::size_t size_{0u};
};

template<typename T>
DoublyCircularList<T>::DoublyCircularList() {
    sentinel = new Node(0);
    sentinel->next(sentinel);
    sentinel->prev(sentinel);
}

template<typename T>
DoublyCircularList<T>::~DoublyCircularList() {
    clear();
    delete sentinel;
}

template<typename T>
void DoublyCircularList<T>::clear() {
    while (size_ > 0) pop_front();
}

template<typename T>
void DoublyCircularList<T>::push_back(const T& data) {
    Node* new_tail = new Node(data, sentinel->prev(), sentinel);
    sentinel->prev()->next(new_tail);
    sentinel->prev(new_tail);
    size_++;
}

template<typename T>
void DoublyCircularList<T>::push_front(const T& data) {
    Node* new_head = new Node(data, sentinel, sentinel->next());
    sentinel->next()->prev(new_head);
    sentinel->next(new_head);
    size_++;
}

template<typename T>
void DoublyCircularList<T>::insert(const T& data, std::size_t index) {
    if (index < 0 || index >= size_) throw std::out_of_range("out of range");
    if (empty()) {
        push_front(data);
        return;
    }

    if (index == 0) {
        push_front(data);
        return;
    }

    if (index == size_ - 1) {
        push_back(data);
        return;
    }

    Node* new_node = new Node(data);
    Node* p;
    if (index < size_/2) {  // 1º metade
        p = sentinel->next();
        for (std::size_t i = 0; i < index; i++) {
            p = p->next();
        }
    } else {  // 2º metade
        p = sentinel->prev();
        for (std::size_t i = size_ - 1; i > index; i--) {
            p = p->prev();
        }
    }

    new_node->next(p);
    new_node->prev(p->prev());

    p->prev()->next(new_node);
    p->prev(new_node);

    size_++;

    return;
}

template<typename T>
void DoublyCircularList<T>::insert_sorted(const T& data) {
    if (empty()) {
        push_front(data);
        return;
    }

    if (!empty()) {
        bool maior = false;
        std::size_t index;
        Node* it = sentinel->next();

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
T DoublyCircularList<T>::pop(std::size_t index) {
    if (index < 0 || index >= size_) throw std::out_of_range("out of range");
    if (empty()) throw std::out_of_range("lista vazia");

    if (index == 0) {
        return pop_front();
    }

    if (index == size_) {
        return pop_back();
    }

    Node* popped;
    if (index < size()/2) {  // 1º metade
        popped = sentinel->next();
        for (std::size_t i = 0; i < index; i++) {
            popped = popped->next();
        }
    } else {  // 2º metade
        popped = sentinel->prev();
        for (std::size_t i = size() - 1; i > index; i--) {
            popped = popped->prev();
        }
    }

    T popped_value = popped->data();

    Node* tmp = popped->next();

    popped->next()->prev(popped->prev());
    popped->prev()->next(tmp);

    delete popped;
    size_--;

    return popped_value;
}
                           
template<typename T>
T DoublyCircularList<T>::pop_back() {
    if (empty()) throw std::out_of_range("lista vazia");

    Node* popped = sentinel->prev();
    Node* new_tail = popped->prev();
    sentinel->prev(new_tail);
    new_tail->next(sentinel);

    T popped_value = popped->data();

    delete popped;
    size_--;

    return popped_value;
}

template<typename T>
T DoublyCircularList<T>::pop_front() {
    if (empty()) throw std::out_of_range("lista vazia");

    Node* popped = sentinel->next();
    Node* new_head = popped->next();
    sentinel->next(new_head);
    new_head->prev(sentinel);

    T popped_value = popped->data();

    delete popped;
    size_--;

    return popped_value;
}

template<typename T>
void DoublyCircularList<T>::remove(const T& data) {
    if (empty()) throw std::out_of_range("lista vazia");

    Node* p = sentinel->next();
    for (std::size_t i = 0; i < size_; i++) {
        if (p->data() == data) {
            pop(i);
            return;
        }
        p = p->next();
    }
}

template<typename T>
bool DoublyCircularList<T>::empty() const{
    return !static_cast<bool>(size_);
}

template<typename T>
bool DoublyCircularList<T>::contains(const T& data) const {
    Node* p = sentinel->next();
    for (std::size_t i = 0; i < size_; i++) {
        if (p->data() == data) return true;
        p = p->next();
    }
    return false;
}

template<typename T>
T& DoublyCircularList<T>::at(std::size_t index) {
    if (index < 0 || index >= size_) throw std::out_of_range("out of range");

    Node* p;
    if (index < size()/2) {  // 1º metade
        p = sentinel->next();
        for (std::size_t i = 0; i < index; i++) {
            p = p->next();
        }
    } else {  // 2º metade
        p = sentinel->prev();
        for (std::size_t i = size() - 1; i > index; i--) {
            p = p->prev();
        }
    }
    return p->data();
}

template<typename T>
const T& DoublyCircularList<T>::at(std::size_t index) const {
    if (index < 0 || index >= size_) throw std::out_of_range("out of range");

    Node* p;
    if (index < size()/2) {  // 1º metade
        p = sentinel->next();
        for (std::size_t i = 0; i < index; i++) {
            p = p->next();
        }
    } else {  // 2º metade
        p = sentinel->prev();
        for (std::size_t i = size() - 1; i > index; i--) {
            p = p->prev();
        }
    }
    return p->data();
}

template<typename T>
std::size_t DoublyCircularList<T>::find(const T& data) const {
    Node* p = sentinel->next();
    for (std::size_t i = 0; i < size_; i++) {
        if (p->data() == data) return i;
        p = p->next();
    }
    return size();
}

template<typename T>
std::size_t DoublyCircularList<T>::size() const {
    return size_;
}

}  // namespace structures

#endif
