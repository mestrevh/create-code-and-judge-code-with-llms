/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);

    if (s.length() < 10) {
        cout << "fracasso" << endl;
        return 0;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSymbol = false;

    for (char c : s) {
        if (isupper(c)) {
            hasUpper = true;
        } else if (islower(c)) {
            hasLower = true;
        } else if (isdigit(c)) {
            hasDigit = true;
        } else if (!isspace(c)) {
            hasSymbol = true;
        }
    }

    if (!hasUpper || !hasLower || !hasDigit || hasSymbol) {
        cout << "fracasso" << endl;
        return 0;
    }

    if (s.rfind("123", 0) == 0 || s.rfind("321", 0) == 0 || s.rfind("000", 0) == 0 || s.rfind("abc", 0) == 0) {
        cout << "fracasso" << endl;
        return 0;
    }
    
    if (s.substr(s.length() - 3) == "123" || s.substr(s.length() - 3) == "321" || s.substr(s.length() - 3) == "000" || s.substr(s.length() - 3) == "abc") {
        cout << "fracasso" << endl;
        return 0;
    }

    cout << "sucesso" << endl;

    return 0;
}
