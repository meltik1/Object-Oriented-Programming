#include "List.h"



template<typename T>
List<T>::List(int length, T args, ...) {
    time_t t_time = time(NULL);

    try {
        this->size = make_shared<size_t>(0);
    }

    catch (bad_alloc &ex) {
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }


    va_list ap;
    va_start(ap, args);
    for (int i = 0; i < length; i++) {
        push_back(args);
        args = va_arg(ap, T);
    }
    va_end(ap);

}

template<typename T>
List<T>::List(initializer_list<T> l) {
    time_t t_time = time(NULL);

    try {
        size = make_shared<size_t>(0);
    }

    catch (bad_alloc &ex)
    {
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    if (l.size() == 0) {
        List();
    }


    for (auto iter = l.begin(); iter != l.end(); iter++) {
        try {
            push_back(*iter);
        }
        catch (BadAlloc &ex) {
            cout << ex.what() << endl;
            throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
    }

}

template<typename T>
List<T>::List(const List<T> &source) {
    time_t t_time = time(NULL);


    this->clear();
    try {
        this->size = make_shared<size_t>(0);
    }

    catch (bad_alloc &ex) {
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    for(auto iter = source.begin(); iter!= source.end(); iter++)
    {
        this->push_back(iter->get_value());
    }
}

template<typename T>
bool List<T>::operator==(const List<T> &other) {

    if (*(this->size) != *(other.size)) {
        return false;
    }

    for (auto iter_1 = this->begin(), iter_2 = other.begin(); iter_1 != this->end(); iter_1++, iter_2++) {
        if (iter_1->get_value() != iter_2->get_value()) {
            return false;
        }
    }

    return true;
}

template<typename T>
bool List<T>::operator!=(const List<T> &other) {
    if (*(this->size) != *(other.size)) {
        return true;
    }

    for (auto iter_1 = this->begin(), iter_2 = other.begin(); iter_1 != this->end(); iter_1++, iter_2++) {
        if (iter_1->get_value() != iter_2->get_value()) {
            return true;
        }
    }

    return false;
}



template<typename T>
bool List<T>::is_empty() {
    return (*size) == 0;
}

template<typename T>
int List<T>::get_length() {
    return *size;
}

template<typename T>
void List<T>::push_back(const T &val) {
    time_t  t_time = time(NULL);
    try {
        if (!head) {
            head = make_shared<Node<T>>(val);
            tail = head;
            (*size)++;
        } else {
            tail->set_next(make_shared<Node<T>>(val));
            tail = tail->get_next();
            (*size)++;
        }
    }
    catch (bad_alloc &ex) {
        cout << ex.what() << endl;
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template<typename T>
void List<T>::push_front(const T &val) {
    time_t  t_time = time(NULL);
    try {
        if (!head) {
            head = make_shared<Node<T>>(val);
            tail = head;
            (*size)++;
        } else
        {
            auto tmp_head  = head;
            head = make_shared<Node<T>>(val);
            head->set_next(tmp_head);
            (*size)++;
        }
    }

    catch (bad_alloc &ex) {
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template<typename T>
void List<T>::pop_back() {

    time_t t_time = time(NULL);

    if (*size <= 0) {
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__,ctime(&t_time));
    }

    for (auto i = this->begin(); i!= this->end(); i++) {
        shared_ptr<Node<T>> tmp = i->get_next();
        if (tmp == tail) {
            i->set_next(nullptr);
            tail = make_shared<Node<T>>(*i);
            (*size)--;
            break;
        }
    }
}

template<typename T>
void List<T>::pop_front() {
    time_t t_time = time(NULL);

    if (*size == 0) {
        throw EmptyError(__FILE__,
                         typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    this->head = this->head->get_next();
    (*size)--;
}

template<typename T>
void List<T>::clear() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void List<T>::push_back(const Node<T> &val) {
    time_t t_time = time(NULL);
    try {
        if (!head) {
            head = make_shared<Node<T>>(val);
            tail = head;
            (*size)++;
        } else {
            tail->set_next(make_shared<Node<T>>(val));
            tail = tail->get_next();
            (*size)++;
        }
    }

    catch (bad_alloc &ex) {
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template<typename T>
void List<T>::push_front(const Node<T> &val) {
    time_t t_time = time(NULL);
    try {
        if (!head) {
            head = shared_ptr<Node<T>>(val);
            tail = head;
            (*size)++;
        } else {
            tail->set_next(shared_ptr<Node<T>>(&val));
            tail = tail->get_next();
            (*size)++;
        }

    }
    catch (bad_alloc &ex) {
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template<typename T>
Iterator<T> List<T>::at(int index) {
    time_t t_time = time(NULL);

    if (index >= *size || index < 0) {
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    Iterator<T> iterator_to_return(head, size);
    for(int i = 1; i <= index; i++) {
        iterator_to_return++;
    }

    return iterator_to_return;
}


template<typename T>
List<T>::List() {
    size = make_shared<size_t>(0);
    head = nullptr;
    tail = nullptr;
}


template<typename T>
List<T>& List<T>::operator=(const List<T> &other) {
    return *this(other);
}

template<typename T>
List<T>& List<T>::operator=(List<T> &&other) noexcept {
    return *this(other);
}

template<typename T>
List<T>& List<T>::operator=(initializer_list<T> l) {
    return *this(l);
}

template<typename T>
List<T>::List(int length, T *args) {
    time_t t_time = time(NULL);
    try {
        size = make_shared<size_t>(0);
    }
    catch (bad_alloc &ex) {
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    if (length <= 0) {
        throw IndalidSize(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    for (int i = 0; i < length; i++) {
        try {
            push_back(args[i]);
        }

        catch (BadAlloc &ex) {
            cout << ex.what() << endl;
            throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime((&t_time)));
        }
    }


}

template<typename T>
List<T>::List(List<T> &&other) noexcept {
    this->size = other.size;
    this->head = other.head;
    this->tail = other.tail;

    other.clear();
}

template<typename Type>
List<Type> List<Type>::merge(const List<Type> &other) {
    time_t t_time = time(NULL);
    try {
        List<Type> merged_list(this);
        for (auto iter = other.begin(); iter!= other.end(); iter++) {
            merged_list->push_back(iter->get_value());
        }
        return merged_list;
    }

    catch (BadAlloc &ex) {
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }


    catch (bad_alloc &ex) {
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }


}

template<typename Type>
Type *List<Type>::to_array(size_t &size_of_array) {
    time_t  t_time = time(NULL);
    try {
        Type *array = new Type[*(this->size)];


        int index = 0;
        for (Iterator<Type> iterator = this->begin(); iterator != this->end(); iterator++, index++) {
            array[index] = iterator->get_value();
        }

        size_of_array = *(size);
        return array;
    }

    catch (bad_alloc &ex) {
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }


}

template<typename Type>
List<Type>::List(iterator<std::random_access_iterator_tag , Type> start,
    iterator<std::random_access_iterator_tag , Type> end) {
    time_t t_time = time(NULL);
    try {
        size = make_shared<size_t>(0);
    }

    catch (bad_alloc &ex) {
        throw  BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    try {
        for (std::iterator<input_iterator_tag, Type> iter = start; iter != end; iter++) {
            push_back(*(iter));
        }
    }

    catch (BadAlloc &ex) {
        throw  BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

}

template<typename Type>
ConstIterator<Type> List<Type>::at(int index) const {
    time_t t_time = time(NULL);

    if (index >= *size || index < 0) {
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    ConstIterator<Type> iterator_to_return(head, size);
    for(int i = 1; i <= index; i++) {
        iterator_to_return++;
    }

    return iterator_to_return;
}


template<typename Type>
void List<Type>::remove(Iterator<Type> iter_source) {
    time_t t_time = time(NULL);

    if (*size <= 0 ) {
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    if (this->begin() == iter_source) {
        pop_front();
        return;
    }

    bool is_found = false;
    for (auto iterator = this->begin(); !is_found &&  iterator != this->end() ; iterator++ ) {
        auto iter_next = iterator->get_next();

        if (iter_next->get_value() == iter_source->get_value()) {
            iterator->set_next(iter_next->get_next());
            (*size)--;
            is_found = true;
        }
    }
}


/*
template<typename T>
void List<T>::insert(int index, const T &val) {
    time_t t_time = time(NULL);


    if (index >= (*size) || index <= 0 ) {
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    try {
        if (index == 0) {
            push_front(val);
            return;
        }


        auto iter = this->begin();

        iter += index - 1;

        shared_ptr<Node<T>> old_node = iter->get_next();
        shared_ptr<Node<T>> new_node = make_shared<Node<T>>(val);
        new_node->set_next(old_node);
        iter->set_next(new_node);
        (*size) ++;
    }

    catch (bad_alloc &ex) {
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    catch (BadAlloc &ex) {
        throw BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

}
 */