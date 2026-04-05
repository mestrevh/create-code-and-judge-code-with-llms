/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;

    int count = 0;
    bool inWord = false;
    for (char c : s) {
        if (isspace(static_cast<unsigned char>(c))) {
            inWord = false;
        } else {
            if (!inWord) {
                count++;
                inWord = true;
            }
        }
    }

    cout << (count % 2 == 0 ? "SIM" : "NÃO");
    return 0;
}