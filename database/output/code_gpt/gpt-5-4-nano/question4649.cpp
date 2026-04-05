/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string letra;
    if (!getline(cin, letra)) return 0;

    if (!letra.empty() && letra.back() == '\r') letra.pop_back();
    if (letra.empty()) return 0;

    char c = letra[0];

    string frase;
    if (!getline(cin, frase)) frase = "";

    if (!frase.empty() && frase.back() == '\r') frase.pop_back();

    size_t pos = frase.find(c);
    if (pos == string::npos) {
        cout << "a frase nao possui a letra";
    } else {
        cout << (pos + 1);
    }
    return 0;
}