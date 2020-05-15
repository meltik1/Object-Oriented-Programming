//
// Created by nikita on 13.05.2020.
//

#ifndef OOP_2_MY_ERRORS_H
#define OOP_2_MY_ERRORS_H

#include <iostream>


using  namespace std;

class ExceptionList: public exception
{
protected:
    string errormessage;
public :
    ExceptionList(const string &filename, const string &classname,
        const int line,
        const string &time, const string &info) {
        errormessage = "In: " + filename + "\nclass :" +
            classname + "\nat line: " + to_string(line) + "\nat:" +
            time + "\n"  + info;
}
    virtual const  char* what() const noexcept override
    {
        return errormessage.c_str();
    }
};

class IndexError: public ExceptionList {
public:
    IndexError(const string &filename, const string &classname,
                  const int line,
                  const string &time, const string info = "index out of range") : ExceptionList(filename, classname, line, time, info) {};

    virtual ~IndexError(){};
};

class BadAlloc: public  ExceptionList {
public:
    BadAlloc(const string &filename, const string &classname,
             const int line,
             const string &time,
             const string info = "Memory allocation error") : ExceptionList(filename, classname, line, time, info) {};

    virtual ~BadAlloc(){};
};

class EmptyError: public ExceptionList {
public:
    EmptyError(const string &filename, const string &classname,
               const int line,
               const string &time, const string info = "memory allocation error") : ExceptionList(filename, classname, line, time, info) {};


    virtual ~EmptyError(){};
};



class IndalidSize: public ExceptionList {
public:
    IndalidSize(const string &filename, const string &classname,
              const int line,
              const string &time, const string info = "invalid size") : ExceptionList(filename, classname, line, time, info) {};

  virtual ~IndalidSize() {};
};

class ObjectDoesNotExist: public  ExceptionList {
public:
    ObjectDoesNotExist( const string &filename, const string &classname,
    const int line,
    const string &time, const string info = "Object does not exist") : ExceptionList(filename, classname, line, time, info) {};
};


#endif //OOP_2_MY_ERRORS_H
