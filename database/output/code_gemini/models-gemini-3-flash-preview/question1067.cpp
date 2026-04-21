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
    if (!getline(cin, s)) {
        cout << "1 caractere, por favor!" << endl;
        return 0;
    }

    if (!s.empty() && s.back() == '\r') {
        s.pop_back();
    }

    if (s.length() != 1) {
        cout << "1 caractere, por favor!" << endl;
    } else {
        char c = s[0];
        char lower_c = (c >= 'A' && c <= 'Z') ? (char)(c + 32) : c;
        if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
            cout << "Eh vogal" << endl;
        } else {
            cout << "Nao eh vogal" << endl;
        }
    }

    return 0;
}