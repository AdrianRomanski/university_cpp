#include <iostream>

using namespace std;

int main() {

    char vowels[] {'a', 'e', 'i', 'o', 'u'};

    cout << vowels[0] << endl;
    cout << vowels[4] << endl;

    int test_scores [5];

    cout << "Enter 5 numbers" << endl;

    cin >> test_scores[0];
    cin >> test_scores[1];
    cin >> test_scores[2];
    cin >> test_scores[3];
    cin >> test_scores[4];

    cout << "1 number: " << test_scores[0] << endl;
    cout << "2 number: " << test_scores[1] << endl;
    cout << "3 number: " << test_scores[2] << endl;
    cout << "4 number: " << test_scores[3] << endl;
    cout << "5 number: " << test_scores[4] << endl;

    cout << test_scores << endl;
}
