// Copyright [2023] <Davi Menegaz Junkes>

#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

template<typename T>
class ArrayList {
 public:
    ArrayList();
    explicit ArrayList(std::size_t max_size);
    ~ArrayList();

    void clear();
    void push_back(const T& data);
    void push_front(const T& data);
    void insert(const T& data, std::size_t index);
    void insert_sorted(const T& data);
    T pop(std::size_t index);
    T pop_back();
    T pop_front();
    void remove(const T& data);
    bool full() const;
    bool empty() const;
    bool contains(const T& data) const;
    std::size_t find(const T& data) const;
    std::size_t size() const;
    std::size_t max_size() const;
    T& at(std::size_t index);
    T& operator[](std::size_t index);
    const T& at(std::size_t index) const;
    const T& operator[](std::size_t index) const;
    // descricao do 'operator []' na FAQ da disciplina

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    static const auto DEFAULT_MAX = 10u;
};

}  // namespace structures

template<typename T>
structures::ArrayList<T>::ArrayList() {
    max_size_ = DEFAULT_MAX;
    contents = new T[max_size_];
    size_ = 0;
}

template<typename T>
structures::ArrayList<T>::ArrayList(std::size_t max_size) {
    max_size_ = max_size;
    contents = new T[max_size_];
    size_ = 0;
}

template<typename T>
structures::ArrayList<T>::~ArrayList() {
    delete [] contents;
}

template<typename T>
void structures::ArrayList<T>::clear() {
    size_ = 0;
}

template<typename T>
void structures::ArrayList<T>::push_back(const T& data) {
    if (full()) {
        throw std::out_of_range("lista cheia");
    } else {
        contents[size_] = data;
        size_++;
    }
}

template<typename T>
void structures::ArrayList<T>::push_front(const T& data) {
    if (full()) {
        throw std::out_of_range("lista cheia");
    } else {
        for (int i = 0; i < static_cast<int>(size_); i++) {
            contents[size_ - i] = contents[size_ - i - 1];
        }
        contents[0] = data;
        size_++;
    }
}

template<typename T>
void structures::ArrayList<T>::insert(const T& data, std::size_t index) {
    if (full()) {
        throw std::out_of_range("lista cheia");
    } else if (index < 0 || index >= size_) {
        throw std::out_of_range("out of range");
    } else {
        for (int i = 0; i < static_cast<int>(index); i++) {
            contents[size_ - i] = contents[size_ - i - 1];
        }
        contents[index] = data;
        size_++;
    }
}

template<typename T>
void structures::ArrayList<T>::insert_sorted(const T& data) {
    if (full()) {
        throw std::out_of_range("lista cheia");
    } else {
        std::size_t index;

        if (empty()) {
            contents[0] = data;
        }
        if (!empty()) {
            bool maior = false;

            for (int i = 0; i < static_cast<int>(size_); i++) {
                if (contents[i] >= data) {
                    index = i;
                    maior = true;
                    break;
                }
            }

            if (maior) {
                for (int i = 0; i < static_cast<int>(size_ - index); i++) {
                    contents[size_ - i] = contents[size_ - i - 1];
                }
                contents[index] = data;
            }
            if (!maior) {
                contents[size_] = data;
            }
        }
        size_++;
    }
}

template<typename T>
T structures::ArrayList<T>::pop(std::size_t index) {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    } else if (index < 0 || index >= size_) {
        throw std::out_of_range("out of range");
    } else {
        T popped = contents[index];
        for (int i = 0; i < static_cast<int>(size_ - index) - 1; i++) {
            contents[index + i] = contents[index + i + 1];
        }
        size_--;

        return popped;
    }
}

template<typename T>
T structures::ArrayList<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    } else {
        size_--;
        T popped = contents[size_];

        return popped;
    }
}

template<typename T>
T structures::ArrayList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    } else {
        T popped = contents[0];
        for (int i = 0; i < static_cast<int>(size_) - 1; i++) {
            contents[i] = contents[i + 1];
        }
        size_--;

        return popped;
    }
}

template<typename T>
void structures::ArrayList<T>::remove(const T& data) {
    size_t index;
    bool find = false;

    for (int i = 0; i < static_cast<int>(size_); i++) {
        if (data == contents[i]) {
            find = true;
            index = i;
            break;
        }
    }

    if (!find) {
        throw std::out_of_range("alvo nao esta na lista");
    }

    for (int i = 0; i < static_cast<int>(size_ - index) - 1; i++) {
        contents[index + i] = contents[index + i + 1];
    }
    size_--;
}

template<typename T>
bool structures::ArrayList<T>::full() const {
    if (size_ == max_size_) {
        return true;
    }
    return false;
}

template<typename T>
bool structures::ArrayList<T>::empty() const {
    if (size_ == 0) {
        return true;
    }
    return false;
}

template<typename T>
bool structures::ArrayList<T>::contains(const T& data) const {
    for (int i = 0; i < static_cast<int>(size_); i++) {
        if (data == contents[i]) {
            return true;
        }
    }
    return false;
}

template<typename T>
std::size_t structures::ArrayList<T>::find(const T& data) const {
    for (int i = 0; i < static_cast<int>(size_); i++) {
        if (data == contents[i]) {
            return i;
        }
    }
    return size_;
}

template<typename T>
std::size_t structures::ArrayList<T>::size() const {
    return size_;
}

template<typename T>
std::size_t structures::ArrayList<T>::max_size() const {
    return max_size_;
}

template<typename T>
T& structures::ArrayList<T>::at(std::size_t index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("out of range");
    }
    return contents[index];
}

template<typename T>
T& structures::ArrayList<T>::operator[](std::size_t index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("out of range");
    }
    return contents[index];
}

template<typename T>
const T& structures::ArrayList<T>::at(std::size_t index) const {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("out of range");
    }
    return contents[index];
}

template<typename T>
const T& structures::ArrayList<T>::operator[](std::size_t index) const {
if (index < 0 || index >= size_) {
        throw std::out_of_range("out of range");
    }
    return contents[index];
}

#endif

