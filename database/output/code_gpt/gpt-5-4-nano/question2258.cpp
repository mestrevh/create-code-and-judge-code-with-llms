/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int contarCaracteres(const string& s) {
    int cont = 0;
    for (char c : s) cont++;
    return cont;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    cout << contarCaracteres(s) << "\n";
    return 0;
}