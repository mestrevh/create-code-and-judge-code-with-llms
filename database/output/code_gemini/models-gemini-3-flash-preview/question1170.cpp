/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    if (s.length() >= 7) {
        char identifier = s[6];
        if (identifier == 'b') {
            cout << "Bulbassauro" << endl;
        } else if (identifier == 'c') {
            cout << "Charmander" << endl;
        } else if (identifier == 's') {
            cout << "Squirtle" << endl;
        } else {
            cout << "Codigo Invalido" << endl;
        }
    } else {
        cout << "Codigo Invalido" << endl;
    }

    return 0;
}