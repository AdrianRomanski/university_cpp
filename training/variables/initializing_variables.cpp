#include <iostream>

using namespace std;

int age = 12;

int main() {

    cout << "Age is: " << age << endl;

    cout << "Enter the width of the room: ";
    int roomWidth = 0;
    cin >> roomWidth;

    cout << "Enter the length of the room: ";
    int roomLength = 0;
    cin >> roomLength;

    cout << "The area of the room is " << roomWidth * roomLength << " square feet" << endl;

    age = 22;

    cout << "Age is: " << age;

    return 0;
}