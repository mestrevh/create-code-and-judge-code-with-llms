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

    if (!s.empty() && s.back() == '\r') s.pop_back();

    string pares, impares;
    for (size_t i = 0; i < s.size(); i++) {
        if (i % 2 == 0) pares += s[i];
        else impares += s[i];
    }

    string rev = s;
    reverse(rev.begin(), rev.end());

    cout << "Somente posições pares: " << pares << "\n";
    cout << "Somente posições ímpares: " << impares << "\n";
    cout << "De trás para frente: " << rev;

    return 0;
}