//
// Created by Adrian Romanski on 20/11/2021.
//
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    string s0;
    string s1 {"Apple"};
    string s2 {"Banana"};
    string s3 {"Kiwi"};
    string s4 {"apple"};
    string s5 {s1};
    string s6 {s1, 0, 3};
    string s7 {10, 'X'};

//    cout << s0 << endl;
//    cout << s0.length() << endl;


    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    cout << s7 << endl;


    return 0;
}
