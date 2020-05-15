//
// Created by nikita on 30.04.2020.
//

#ifndef OOP_2_NODE_H
#define OOP_2_NODE_H

#include "BaseNode.h"
# include <memory>
# include <iterator>
# include <initializer_list>

using namespace std;
template <typename T>
class Node: public  BaseNode{
public:
    Node();
    explicit Node(T value);
    Node(T value, shared_ptr<Node<T>> next);
    Node(const Node<T> &other);
    Node(Node<T>&& other) noexcept ;


    Node<T>& operator=(const Node<T> &other);
    Node<T>&operator=(Node<T> &&other) noexcept ;

    void set_value(const T &value);

    T& get_value();
    const T& get_value() const;


    void set_next(shared_ptr<Node<T>> value);

    shared_ptr<Node<T>> get_next();
    const shared_ptr<Node<T>> get_next() const;

    void update_value(T value);

    bool operator ==(Node<T> &node);
    bool operator !=(Node<T> &node);

    virtual ~Node(){};

private:
    T value;
    shared_ptr<Node<T>> next;
};



#endif //OOP_2_NODE_H


