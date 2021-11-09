
#include <iostream>

using namespace std;
using std::cout; using std::endl;

#include <set>

void checkCharacters(const std::set<char>& chars, bool *checking) {
    bool isDigit = false;
    bool isUpperCase = false;
    bool isLower = false;
    bool isSpecialSymbol = false;
    for (char item : chars) {
        if(isdigit(item)) {
            isDigit=true;
        } else if(isupper(item)) {
            isUpperCase=true;
        } else if(islower(item)) {
            isLower=true;
        }  else if(!iswalnum(item)) {
            isSpecialSymbol=true;
        }
    }
    if(isDigit==0) {
        *checking=false;
        cout << "password should have at least one digit" << endl;
    }
    if(isUpperCase==0) {
        *checking=false;
        cout << "password should have at least one upper case letter"<< endl;
    }
    if(isLower==0) {
        *checking=false;
        cout << "password should have at least one lower case letter"<< endl;
    }
    if(isSpecialSymbol==0) {
        *checking=false;
        cout << "password should have at least one special symbol"<< endl;
    }
}

void checkDifferentChars(const char* pass, bool *checking) {
    std::set<char> chars;
    for (int i = 0; i < strlen(pass); i++) {
        chars.insert(pass[i]);
    }
    if(chars.size() < 6) {
        *checking = false;
        cout << "password have to contains 6 or more different characters" << endl;
    }
    return checkCharacters(chars, checking);
}

void checkPassLength(const char* pass, bool *checking) {
    if(strlen(pass) < 8) {
        *checking = false;
        cout << "password length have to be longer than 7" << endl;
    }
    checkDifferentChars(pass, checking);
}

bool checkPass(const char* pass) {
    bool checking = true;
    checkPassLength(pass, &checking);
    return checking;
}

int main() {
    const char *passes[] ={
                    "AbcDe93", "A1b:A1b>", "Ab:Acb<",
                    "abc123><", "Zorro@123", nullptr
    };
    for (int i = 0; passes[i] != nullptr; ++i) {
        cout << "checking " << passes[i] << endl;
        if (checkPass(passes[i])) cout << "OK" << endl;
        cout << endl;
    }
}