//
// Created by Adrian Romanski on 28/11/2021.
//

#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

class Rect {
    int a;
    int b;

public:
    Rect(): a(1) {}
    Rect(int a) : a(a) {}
    Rect(int a, int b) : a(a), b(b) {}

    int getA() const {
        return a;
    }

    int getB() const {
        return b;
    }

    double getPrzekatna() const {
        return sqrt(pow(a, 2) + pow(b, 2));
    };

    double getPole() const {
        return a * b;
    };

    bool isLargerThan(const Rect& rect) const {
        return this->getPole() > rect.getPole();
    }

    void info() const {
        cout << "[" << this->a << "," << this->b << "]";
    }
};


int main() {


    Rect rect = {2,2};
    Rect rect2 = {4, 4};

    cout << rect.getPole() << endl;
    cout << rect.getPrzekatna() << endl;

    cout << "is ";
    rect.info();
    cout << " larger than ";
    rect2.info();
    cout << endl;
    cout << rect.isLargerThan(rect2);



    return -1;
}

