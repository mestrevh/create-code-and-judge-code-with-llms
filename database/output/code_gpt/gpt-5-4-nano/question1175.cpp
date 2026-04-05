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
    if (s.size() != 10) {
        cout << "Codigo Invalido";
        return 0;
    }
    
    char seventh = s[6];
    if (seventh == 'b' || seventh == 'B') cout << "Bulbassauro";
    else if (seventh == 'c' || seventh == 'C') cout << "Charmander";
    else if (seventh == 's' || seventh == 'S') cout << "Squirtle";
    else cout << "Codigo Invalido";
    
    return 0;
}