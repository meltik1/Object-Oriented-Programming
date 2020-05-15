//
// Created by nikita on 07.05.2020.
//

#ifndef OOP_2_CONSTITERATOR_H
#define OOP_2_CONSTITERATOR_H

#include <iostream>
# include <memory>
# include <iterator>
# include <initializer_list>
#include "Node.h"
#include "my_errors.h"



using  namespace std;
template <typename Type>
class ConstIterator : public std::iterator<std::output_iterator_tag, Type>
{
public:
    ConstIterator(const shared_ptr<Node<Type>> a, const shared_ptr<size_t> c, size_t ind = 0) : current_node(a),
                                                                                                list_length(c), index(ind) {}
    ConstIterator(const ConstIterator &it) = default;


    const Node<Type> & operator*() const;
    const Node<Type>* operator->() const;

    ConstIterator<Type>& operator+=(int n);
    ConstIterator<Type>& operator++();
    ConstIterator<Type>& operator++(int);

    bool checker(int line) const ;
    operator bool() const;



    bool operator!=(ConstIterator const &other) const;
    bool operator==(ConstIterator const &other) const;

private:
    weak_ptr<Node<Type>> current_node;
    weak_ptr<size_t> list_length;
    size_t  index;
};

template<typename Type>
bool ConstIterator<Type>::operator!=(ConstIterator const &other) const {
    return current_node.lock() != other.current_node.lock();
}

template<typename Type>
bool ConstIterator<Type>::operator==(ConstIterator const &other) const {
    return current_node.lock() == other.current_node.lock();
}



template<typename Type>
const Node<Type> &ConstIterator<Type>::operator*() const {
    checker(__LINE__);
    const  shared_ptr<Node<Type>> a(current_node);

    return *a;
}


template<typename Type>
const Node<Type> *ConstIterator<Type>::operator->() const {
    checker(__LINE__);
    const shared_ptr<Node<Type>> a(current_node);

    return (a.get());
}

template<typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator++() {
    checker(__LINE__);
    shared_ptr<size_t> n(list_length);
    shared_ptr<Node<Type>> new_head(current_node);
    if (index <= *n) {
        index++;
        current_node = weak_ptr(new_head->get_next());
    }
    return *this;
}

template<typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator++(int) {
    checker(__LINE__);
    ConstIterator<Type> it (*this);
    ++(*this);
    return  *this;
}

template<typename Type>
ConstIterator<Type> &ConstIterator<Type>::operator+=(int n) {
    checker(__LINE__);
    ConstIterator<Type> it(*this);

    for (int i = 0; i  < n; i++) {
        ++it;
    }

    return (*this);
}

template<typename Type>
bool ConstIterator<Type>::checker(int line) const {
    if (!current_node.expired())
        return true;

    time_t t_time = time(NULL);
    throw ObjectDoesNotExist(__FILE__, typeid(*this).name(), line, ctime(&t_time));

}

template<typename Type>
ConstIterator<Type>::operator bool() const {
    checker(__LINE__);
    return (index >= 0 && index < *(list_length.lock()));
}


#endif //OOP_2_ITERATOR_H
