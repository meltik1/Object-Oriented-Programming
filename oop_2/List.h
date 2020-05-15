//
// Created by nikita on 30.04.2020.
//

#ifndef OOP_2_LIST_H
#define OOP_2_LIST_H

#include <iostream>
#include <initializer_list>
#include <memory>
#include <type_traits>
#include <typeinfo>
#include <stdarg.h>
#include "my_errors.h"
#include "Node.h"
#include "BaseList.h"
#include "Iterator.h"
#include  "СonstIterator.h"

using  namespace std;
template <typename Type>

class List: public BaseList {
public:

    List ();
    List(int length, Type args, ...);
    List(int size, Type* args);
    List(std::initializer_list<Type> l);
    explicit List(const List<Type> &source);
    List(List<Type> &&other) noexcept ;
    List(std::iterator<std::random_access_iterator_tag , Type> start, std::iterator<std::random_access_iterator_tag , Type> end);

    Iterator<Type> begin()  { return Iterator<Type>(head, size); }
    Iterator<Type> end()   { return Iterator<Type>(nullptr, size, *size);}
    Iterator<Type> at(int index) ; //


    ConstIterator<Type> cbegin() const { return ConstIterator<Type>(head, size);}
    ConstIterator<Type> cend() const { return  ConstIterator<Type>(nullptr, size, *size);}
    ConstIterator<Type> at(int index) const;
    ConstIterator<Type> begin() const { return  ConstIterator<Type>(head, size);}
    ConstIterator<Type> end() const { return ConstIterator<Type>(nullptr, size, *size);}

    List<Type>& operator=(const List<Type>& other);
    List<Type>& operator=(List<Type> &&other) noexcept ;
    List<Type>& operator=(std::initializer_list<Type> l);


    bool operator ==(const List<Type> & other);
    bool operator !=(const List<Type> & other);

    void push_back(const Type &val);
    void pop_back();



    void push_front(const Type &val);
    void pop_front();

    void clear();

    bool is_empty() override ;

    int get_length() override ;

    List<Type> merge(const List<Type> &other);
    Type* to_array(size_t& size_of_array);

    void remove(Iterator<Type> iter_source);
    void insert(Iterator<Type> iter_source, Type &val); // Реализуй что то похожее что ты найдешь внизу List.hpp

private:
    void push_back(const Node<Type> &val);
    void push_front(const Node<Type> &val);

private:
    shared_ptr<size_t> size;
    shared_ptr<Node<Type>> head;
    shared_ptr<Node<Type>> tail;
};


template<typename Type>
std::ostream& operator <<(std::ostream& os, List<Type>& list)
{
    if (list.is_empty()) {
        os << "List is empty";
        return os;
    }

    os << "[";
    for (auto iter = list.begin(); iter != list.end(); iter++) {
        os << iter->get_value() << ", ";
    }
    os << "]";

    return os;
}



#endif //OOP_2_LIST_H
