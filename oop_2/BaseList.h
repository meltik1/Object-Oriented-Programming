//
// Created by nikita on 30.04.2020.
//

#ifndef OOP_2_BASELIST_H
#define OOP_2_BASELIST_H


class BaseList {
private:
    int size;
public:
    virtual bool is_empty() = 0;
    virtual int get_length() = 0;
    // virt destrcutor
};


#endif //OOP_2_BASELIST_H
