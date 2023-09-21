//! Copyright [2023] <Davi Menegaz Junkes>
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

template<typename T>
class DoublyLinkedList {
 public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void clear();

    void push_back(const T& data);  // insere no fim
    void push_front(const T& data);  // insere no início
    void insert(const T& data, std::size_t index);  // insere na indexição
    void insert_sorted(const T& data);  // insere em ordem

    T pop(std::size_t index);  // retira da indexição
    T pop_back();  // retira do fim
    T pop_front();  // retira do início
    void remove(const T& data);  // retira específico

    bool empty() const;  // lista vazia
    bool contains(const T& data) const;  // contém

    T& at(std::size_t index);  // acesso a um elemento (checando limites)
    const T& at(std::size_t index) const;  // getter constante a um elemento

    std::size_t find(const T& data) const;  // indexição de um dado
    std::size_t size() const;  // tamanho

    void check() const {
        if (size_ == 0) {
            if (head || tail) {
                printf("size = 0, head e tail invalidos\n");
                fflush(stdout);
            }
        } else {
            if (!head || !tail) {
                printf("size != 0, head e tail invalidos\n");
                fflush(stdout);
            }
            Node* prev = 0;
            Node* curr = head;
            std::size_t i = 0;
            while (curr) {
                if (curr->prev() != prev) {
                    printf("lista invalida\n");
                    fflush(stdout);
                }

                i++;
                prev = curr;
                curr = curr->next();
            }
            if (i != size_) {
                printf("i = size invalido\n");
                fflush(stdout);
            }
        }
    }

 private:
    class Node {
     public:
        Node(const T& data):
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

        void prev(Node* node) { // setter
            prev_ = node;
        }

        Node* next() {
            return next_;
        }
        const Node* next() const {
            return next_;
        }

        void next(Node* node) { // setter
            next_ = node;
        }

     private:
        T data_;
        Node* prev_{nullptr};
        Node* next_{nullptr};
    };

    Node* head{nullptr};  // primeiro da lista
    Node* tail{nullptr};  // ultimo da lista
    std::size_t size_{0};
};

template<typename T>
structures::DoublyLinkedList<T>::DoublyLinkedList() {}

template<typename T>
structures::DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
void structures::DoublyLinkedList<T>::clear() {
    check();
    while (size_ > 0) pop_front();
}

template<typename T>
void structures::DoublyLinkedList<T>::push_back(const T& data) {
    Node* new_tail = new Node(data, tail, nullptr);
    if (!empty()) tail->next(new_tail);
    if (empty()) head = new_tail;
    tail = new_tail;
    size_++;
}

template<typename T>
void structures::DoublyLinkedList<T>::push_front(const T& data) {
    Node* new_head = new Node(data, nullptr, head);
    if (!empty()) head->prev(new_head);
    if (empty()) tail = new_head;
    head = new_head;
    size_++;
}

template<typename T>
void structures::DoublyLinkedList<T>::insert(const T& data, std::size_t index) {
    if (empty()) {
        push_front(data);
        return;
    }

    Node* new_node = new Node(data);

    Node* p;
    if (index < size()/2) {  // 1º metade
        p = head;
        for (std::size_t i = 0; i < index; i++) {
            p = p->next();
        }
    } else {  // 2º metade
        p = tail;
        for (std::size_t i = size() - 1; i > index; i--) {
            p = p->prev();
        }
    }

    new_node->next(p->next());
    new_node->prev(p->prev());

    p->next()->prev(new_node);
    p->prev()->next(new_node);

    size_++;

    return;
}

template<typename T>
void structures::DoublyLinkedList<T>::insert_sorted(const T& data) {
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
T structures::DoublyLinkedList<T>::pop(std::size_t index) {
    if (empty()) throw std::out_of_range("lista vazia");

    Node* popped;
    if (index < size()/2) {  // 1º metade
        popped = head;
        for (std::size_t i = 0; i < index; i++) {
            popped = popped->next();
        }
    } else {  // 2º metade
        popped = tail;
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
T structures::DoublyLinkedList<T>::pop_back() {
    if (empty()) throw std::out_of_range("lista vazia");

    Node* popped = tail;
    tail = tail->prev();

    if (tail) {
        tail->next(nullptr);
    } else {
        head = nullptr;
    }

    T popped_value = popped->data();

    delete popped;
    size_--;

    return popped_value;
}

template<typename T>
T structures::DoublyLinkedList<T>::pop_front() {
    if (empty()) throw std::out_of_range("lista vazia");

    Node* popped = head;
    head = head->next();

    if (head) {
        head->prev(nullptr);
    } else {
        tail = nullptr;
    }

    T popped_value = popped->data();

    delete popped;
    size_--;

    return popped_value;
}

template<typename T>
void structures::DoublyLinkedList<T>::remove(const T& data) {
    if (empty()) throw std::out_of_range("lista vazia");

    Node* p;

    for (std::size_t i = 0; i < size_; i++) {
        if (p->data() == data) {
            pop(i);
            return;
        }
        p = p->next();
    }
}

template<typename T>
bool structures::DoublyLinkedList<T>::empty() const{
    return !static_cast<bool>(size_);
}

template<typename T>
bool structures::DoublyLinkedList<T>::contains(const T& data) const {
    Node* p;

    for (std::size_t i = 0; i < size_; i++) {
        if (p->data() == data) return true;
        p = p->next();
    }
    return false;
}

template<typename T>
T& structures::DoublyLinkedList<T>::at(std::size_t index) {
     Node *p;
     if (index < size()/2) {  // 1º metade
         p = head;
         for (std::size_t i = 0; i < index; i++) {
             p = p->next();
         }
     } else {  // 2º metade
         p = tail;
         for (std::size_t i = size() - 1; i > index; i--) {
             p = p->prev();
         }
     }
     return p->data();
}

template<typename T>
const T& structures::DoublyLinkedList<T>::at(std::size_t index) const {
     Node *p;
     if (index < size()/2) {  // 1º metade
         p = head;
         for (std::size_t i = 0; i < index; i++) {
             p = p->next();
         }
     } else {  // 2º metade
         p = tail;
         for (std::size_t i = size() - 1; i > index; i--) {
             p = p->prev();
         }
     }
     return p->data();
}

template<typename T>
std::size_t structures::DoublyLinkedList<T>::find(const T& data) const {
    Node* p;

    check();
    for (std::size_t i = 0; i < size_; i++) {
        if (p->data() == data) return i;
        p = p->next();
    }
    check();
    return size();
}

template<typename T>
std::size_t structures::DoublyLinkedList<T>::size() const {
    return size_;
}

} // namespace structures

#endif

