/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    bool cap = true;
    while (getline(cin, line)) {
        for (char c : line) {
            char d = c;
            switch (c) {
                case '0': d = 'o'; break;
                case '1': d = 'i'; break;
                case '2': d = 'u'; break;
                case '4': d = 'a'; break;
                case '5': d = 'e'; break;
            }

            if (cap && isalpha((unsigned char)d)) {
                d = (char)toupper((unsigned char)d);
                cap = false;
            } else if (d == '.') {
                cap = true;
            }
            cout << d;
        }
        cout << '\n';
    }

    return 0;
}