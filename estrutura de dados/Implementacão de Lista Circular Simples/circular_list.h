//! Copyright [2023] <Davi Menegaz Junkes>
#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

template<typename T>
class CircularList {
 public:
    CircularList();
    ~CircularList();

    void clear();  // limpar lista

    void push_back(const T& data);  // inserir no fim
    void push_front(const T& data);  // inserir no in├¡cio
    void insert(const T& data, std::size_t index);  // inserir na posi├º├úo
    void insert_sorted(const T& data);  // inserir em ordem

    T& at(std::size_t index);  // acessar em um indice (com checagem de limites)
    const T& at(std::size_t index) const;  // vers├úo const do acesso ao indice

    T pop(std::size_t index);  // retirar da posi├º├úo
    T pop_back();  // retirar do fim
    T pop_front();  // retirar do in├¡cio
    void remove(const T& data);  // remover dado espec├¡fico

    bool empty() const;  // lista vazia
    bool contains(const T& data) const;  // lista cont├⌐m determinado dado?
    std::size_t find(const T& data) const;  // posi├º├úo de um item na lista

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

        Node* next() {  // getter: pr├│ximo
            return next_;
        }

        const Node* next() const {  // getter const: pr├│ximo
            return next_;
        }

        void next(Node* node) {  // setter: pr├│ximo
            next_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };

    Node* sentinel{nullptr};
    std::size_t size_{0u};
};

template<typename T>
CircularList<T>::CircularList() {
    Node* sen = new Node(0, nullptr);
    sentinel = sen;
}

template<typename T>
CircularList<T>::~CircularList() {
    clear();
    delete sentinel;
}

template<typename T>
void CircularList<T>::clear() {
    while (size() > 0) {
        pop_front();
    }
}

template<typename T>
void CircularList<T>::push_back(const T& data) {
    if (size() > 0) {
        Node* tail = sentinel->next();
        for (int i = 0; i < static_cast<int>(size_) - 1; i++) {
            tail = tail->next();
        }
        Node* new_tail = new Node(data, sentinel);
        tail->next(new_tail);
        size_++;

    } else {
        push_front(data);
    }
}

template<typename T>
void CircularList<T>::push_front(const T& data) {
    Node* new_first = new Node(data, sentinel->next());
    sentinel->next(new_first);
    size_++;
}

template<typename T>
void CircularList<T>::insert(const T& data, std::size_t index) {
    if (index < 0 || index > size_) throw std::out_of_range("out of range");

    if (!index) push_front(data);
    if (index == size_) {
        push_back(data);
        return;
    }

    if (index) {
        Node* it = sentinel->next();  // next pos
        Node* previous;
        for (int i = 0; i < static_cast<int>(index); i++) {
            previous = it;
            it = it->next();
        }
        Node* new_node = new Node(data, it);
        previous->next(new_node);
        size_++;
    }
}

template<typename T>
void CircularList<T>::insert_sorted(const T& data) {
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
T& CircularList<T>::at(std::size_t index) {
    if (index < 0 || index >= size_) throw std::out_of_range("out of range");

    Node* it = sentinel->next();
    for (int i = 0; i < static_cast<int>(index); i++) {
        it = it->next();
    }
    return it->data();
}

template<typename T>
const T& CircularList<T>::at(std::size_t index) const {
    if (index < 0 || index >= size_) throw std::out_of_range("out of range");

    Node* it = sentinel->next();
    for (int i = 0; i < index; i++) {
        it = it->next();
    }
    return it->data();
}

template<typename T>
T CircularList<T>::pop(std::size_t index) {
    if (empty()) throw std::out_of_range("lista vazia");
    if (index < 0 || index >= size_) throw std::out_of_range("out of range");

    T popped_value;
    if (!index) popped_value = pop_front();
    if (index == size_ - 1) return pop_back();

    if (index) {
        Node* popped = sentinel->next();
        Node* previous;
        for (int i = 0; i < static_cast<int>(index); i++) {
            previous = popped;
            popped = popped->next();
        }
        popped_value = popped->data();
        previous->next(popped->next());
        delete popped;
        size_--;
    }


    return popped_value;
}

template<typename T>
T CircularList<T>::pop_back() {
    if (empty()) throw std::out_of_range("lista vazia");

    if (size_ > 1) {
        Node* new_end;
        Node* popped = sentinel->next();
        for (int i = 1; i < static_cast<int>(size_); i++) {
            new_end = popped;
            popped = popped->next();
        }

        new_end->next(sentinel);

        T popped_value = popped->data();
        delete popped;
        size_--;

        return popped_value;
    } else {
        return pop_front();
    }
}

template<typename T>
T CircularList<T>::pop_front() {
    if (empty()) throw std::out_of_range("lista vazia");

    Node* popped = sentinel->next();
    sentinel->next(popped->next());

    T popped_value = popped->data();
    delete popped;
    size_--;

    return popped_value;
}

template<typename T>
void CircularList<T>::remove(const T& data) {
    if (empty()) throw std::out_of_range("lista vazia");

    Node* it = sentinel->next();
    Node* previous;

    for (int i = 1; i < static_cast<int>(size_); i++) {
        if (data == it->data()) {
            previous->next(it->next());
            delete it;
            break;
        }
        previous = it;
        it = it->next();
    }
    size_--;
}

template<typename T>
bool CircularList<T>::empty() const {
    return !static_cast<bool>(size_);
}

template<typename T>
bool CircularList<T>::contains(const T& data) const {
    Node* it = sentinel->next();
    for (int i = 1; i < static_cast<int>(size_); i++) {
        if (it->data() == data) return true;
        it = it->next();
    }
    return false;
}

template<typename T>
std::size_t CircularList<T>::find(const T& data) const {
    Node* it = sentinel->next();
    for (int i = 0; i < static_cast<int>(size_); i++) {
        if (it->data() == data) return i;
        it = it->next();
    }
    return(size());
}

template<typename T>
std::size_t CircularList<T>::size() const {
    return size_;
}


}  // namespace structures

#endif

