/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string word, phrase, temp;
    getline(cin, word);
    getline(cin, phrase);

    stringstream ss(phrase);
    bool found = false;

    while (ss >> temp) {
        if (temp == word) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "existe!" << endl;
    } else {
        cout << "nao existe" << endl;
    }

    return 0;
}
