#include <iostream>
#include "Node.hpp"
#include "List.hpp"
#include <vector>
#include <algorithm>




using  namespace std;

int main() {
    try {
        List<int> a(1, 10);
        a.push_back(5);


        // Testing constructor with various args
        for (auto iter = a.begin(); iter != a.end(); iter++) {
            cout << iter->get_value()  << endl;
        }

        cout << "-------------------------------" << endl << "TESTING PUSHES AND POPS" << endl;

        // testing push_front
        a.push_front(2);
        a.push_back(3);
        a.push_back(5);

        cout << a << endl;

        cout << a << endl;

        // copy constructor
        List<int> b(a);

        // testing overloaded ==
        if (a == b) {
            cout << "a == b" << endl;
        }

        for (auto iter = b.begin(); iter != b.end(); iter++) {
            cout << iter->get_value() << endl;
        }

        b.pop_back();

        cout << "b was popped back" << endl;

        cout << b << endl;

        b.pop_front() ;

        cout << "b was popped front" << endl;

        cout << b;

        cout << "END TESTING PUSHES AND POPS" << endl;
        cout << "-------------------------------" << endl;




        // testing constructors
        cout << "-------------------------------" << endl << "TESTING CONSTRUCTORS" << endl;

        List<double> c = {2.4, 1, 0 ,3};

        cout << "C - list" << endl;
        cout << c << endl;

        List<int> d(4,2,3,4,5);
        cout << "D - list" << endl;
        cout << d << endl;

        int massive[5]{1,2,3};

        List<int> testing_array_to_List(3, massive);

        cout << "array to list" << endl;
        cout << testing_array_to_List << endl;

        size_t  size;
        int* list_to_array = testing_array_to_List.to_array(size);


        // testing == and !=

        List<int> d_copy(d);

        if (d == d_copy) {
            cout << "d == d_copy" << endl;
        }

        else {
            cout << "ERROR" << endl;
        }

        if (d != d_copy) {
            cout << "d! = d_copy" << endl;
        }

        else {
            cout << "OK" << endl;
        }




        // testing non const at
        if (c.at(0) == c.begin()) {
            cout << "OK" << endl;
        }


        // testing const
        const List<double> f = {2,3 ,5,6 ,7};

        cout << "Testing const at: "  << f.at(1)->get_value() << endl;

        cout << "Testing iterators in const" << endl;
        for (auto iter = f.begin(); iter != f.end(); iter++) {
            cout <<  iter->get_value() << " ";
        }

       List<int> *merged_list(d.merge(a));


    }

    catch (ExceptionList &exceptionList) {
        cout << exceptionList.what();
    }

}