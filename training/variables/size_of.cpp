#include <iostream>
#include <climits>

using namespace std;

int main() {

    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "long: " << sizeof(long) << " bytes" << endl;


    cout << "char: " << CHAR_MIN << " min" << endl;
    cout << "char: " << CHAR_MAX << " max" << endl;

    int age = 21;

    cout << "age: " << sizeof(age) << " bytes" << endl;
}
