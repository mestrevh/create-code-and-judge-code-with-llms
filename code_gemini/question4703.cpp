/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int contar_vogais(string s, char vogal) {
    int count = 0;
    for (char c : s) {
        if (tolower(c) == tolower(vogal)) {
            count++;
        }
    }
    return count;
}

int main() {
    string s;
    getline(cin, s);

    cout << "A: " << contar_vogais(s, 'a') << endl;
    cout << "E: " << contar_vogais(s, 'e') << endl;
    cout << "I: " << contar_vogais(s, 'i') << endl;
    cout << "O: " << contar_vogais(s, 'o') << endl;
    cout << "U: " << contar_vogais(s, 'u') << endl;

    return 0;
}
