//
// Created by Adrian Romanski on 20/11/2021.
//
#include <iostream>

using namespace std;

int main() {


    int test = 2;

    int *testPointer = &test;

    int *copiedPointer = testPointer;

//    cout << testPointer << endl;
//
//    cout << *testPointer << endl;
//
//    cout << copiedPointer << endl;
//
//    cout << *copiedPointer << endl;
//
//    *testPointer = 400;
//
//    cout << test << endl;

//    dynamic memory allocation

//    cout << "dynamic memory allocation" << endl;

    int *int_ptr {nullptr};
    int_ptr = new int;

    cout << int_ptr <<  endl;

    delete int_ptr;

    size_t size{0};

    double *temp_ptr {nullptr};

    cout << "How many temps? ";
    cin >> size;

    temp_ptr = new double[size];

    cout << temp_ptr << endl;

    delete [] temp_ptr;

    return 0;
}

