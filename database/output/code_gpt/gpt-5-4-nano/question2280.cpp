/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int contar(const string& s) {
    if (s.empty()) return 0;
    return 1 + contar(s.substr(1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    cout << contar(s) << "\n";
    return 0;
}