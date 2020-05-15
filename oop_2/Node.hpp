//
// Created by nikita on 30.04.2020.
//

#include "Node.h"

template<typename T>
Node<T>::Node() {
    this->value = 0;
    this->next = nullptr;
}

template<typename T>
Node<T>::Node(T value) {
    this->value = value;
    this->next = nullptr;
}

template<typename T>
Node<T>::Node(T value, shared_ptr<Node<T>> next) {
    this->value = value;
    this->next = next;
}



template<typename T>
void Node<T>::set_value(const T& source) {
    this->value = source;
}

template<typename T>
T& Node<T>::get_value() {
    return this->value;
}

template<typename T>
const T &Node<T>::get_value() const {
    return this->value;
}

template<typename T>
void Node<T>::update_value(const T source) {
    this->value = source;
}





template <typename  T>
bool  Node<T>::operator ==(Node<T> &node) {
    return this->value == node.value;
}
template <typename T>
bool  Node<T>::operator!=(Node<T> &node) {
    return !(this->value == node.value);
}


template<typename T>
const shared_ptr<Node<T>> Node<T>::get_next() const {
    return this->next;
}

template<typename T>
shared_ptr<Node<T>> Node<T>::get_next() {
    return this->next;
}

template<typename T>
void Node<T>::set_next(shared_ptr<Node<T>> val) {
    this->next = val;
}

template<typename T>
Node<T>::Node(const Node<T> &other) {
    this->value = other.value;
    this->next = shared_ptr<Node<T>>(other.next);
}

template<typename T>
Node<T> &Node<T>::operator=(const Node<T> &other) {
    return *this(other);
}

template<typename T>
Node<T>::Node(Node<T> &&other) noexcept {
    this->value = other.value;
    this->next = other.next;

    other.next = nullptr;

}

template<typename T>
Node<T> &Node<T>::operator=(Node<T> &&other) noexcept {
    return *this(other);
}

