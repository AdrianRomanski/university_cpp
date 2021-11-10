#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector <char> vowels {'a', 'e', 'i', 'o', 'u'};
    vector <int> test_scores (10);


    cout << vowels.at(0) << endl;

    vowels.push_back('z');

    cout << vowels.at(vowels.size() - 1) << endl;

    vector <vector<int>> movie_ratings {
            {1,2,3,4},
            {1,2,3,4},
            {1,2,3,4}
    };

    cout << movie_ratings[0][0] << endl;
    cout << movie_ratings.at(1).at(1) << endl;

}
