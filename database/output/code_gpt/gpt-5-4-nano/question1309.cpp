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
    if (!(cin >> s)) return 0;
    if (s == "F") cout << "Feminino";
    else if (s == "M") cout << "Masculino";
    else cout << "Sexo nao definido";
    return 0;
}