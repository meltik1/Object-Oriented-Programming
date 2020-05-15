//
// Created by nikita on 07.05.2020.
//

#ifndef OOP_2_ITERATOR_H
#define OOP_2_ITERATOR_H

#include <iostream>
# include <memory>
# include <iterator>
# include <initializer_list>
#include "Node.h"
#include "my_errors.h"



using  namespace std;
template <typename Type>
class Iterator : public std::iterator<std::input_iterator_tag, Type>
{
public:
    Iterator(const shared_ptr<Node<Type>> a, const shared_ptr<size_t> c, size_t ind = 0) : current_node(a),
                                                                                           count(c), index(ind) {}
    Iterator(const Iterator &it) = default;

    Node<Type>& operator*();
    const Node<Type> & operator*() const;
    Node<Type>* operator->();
    const Node<Type>* operator->() const;

    Iterator<Type>& operator+=(int n);
    Iterator<Type>& operator++();
    Iterator<Type> operator++(int);

    void checker(int line) const;
    operator bool() const;


    bool operator!=(Iterator const &other) const;
    bool operator==(Iterator const &other) const;

private:
    weak_ptr<Node<Type>> current_node;
    weak_ptr<size_t> count;
    size_t  index;
};

template<typename Type>
bool Iterator<Type>::operator!=(Iterator const &other) const {
    return current_node.lock() != other.current_node.lock();
}

template<typename Type>
bool Iterator<Type>::operator==(Iterator const &other) const {
    return current_node.lock() == other.current_node.lock();
}

template<typename Type>
Node<Type> &Iterator<Type>::operator*() {
    checker(__LINE__);
    shared_ptr<Node<Type>> a(current_node);

    return *a;
}

template<typename Type>
const Node<Type> &Iterator<Type>::operator*() const {
    checker(__LINE__);
    const  shared_ptr<Node<Type>> a(current_node);

    return *a;
}

template<typename Type>
Node<Type> *Iterator<Type>::operator->() {
    checker(__LINE__);
    shared_ptr<Node<Type>> a(current_node);

    return a.get();
}

template<typename Type>
const Node<Type> *Iterator<Type>::operator->() const {
    checker(__LINE__);
    const shared_ptr<Node<Type>> a(current_node);

    return *a;
}

template<typename Type>
Iterator<Type>& Iterator<Type>::operator++() {
    checker(__LINE__);
    shared_ptr<size_t> n(count);
    shared_ptr<Node<Type>> new_head(current_node);
    if (index <= *n) {
        index++;
        current_node = weak_ptr(new_head->get_next());
    }

    else {
        time_t t_time = time(NULL);
        throw IndexError(__FILE__, typeid((*this)).name(), __LINE__, ctime(&t_time));
    }
    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator++(int) {
    checker(__LINE__);
    Iterator<Type> it (*this);
    ++(*this);
    return  it;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator+=(int n) {
    checker(__LINE__);
    Iterator<Type> it(*this);

    for (int i = 0; i  < n; i++) {
        ++it;
    }

    return (*this);
}

template<typename Type>
void Iterator<Type>::checker(int line) const {
    if (!current_node.expired())
        return ;

    time_t t_time = time(NULL);
    throw ObjectDoesNotExist(__FILE__, typeid(*this).name(), line, ctime(&t_time));

}

template<typename Type>
Iterator<Type>::operator bool() const {
    checker(__LINE__);
    return (index >= 0 && index < *(count.lock()));
}


#endif //OOP_2_ITERATOR_H
