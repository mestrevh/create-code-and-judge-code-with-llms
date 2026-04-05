/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int P;
    if (!(cin >> P)) return 0;
    
    string nome;
    if (P == 1) nome = "Bulbassauro";
    else if (P == 2) nome = "Charmander";
    else if (P == 3) nome = "Squirtle";
    
    cout << nome << "\n";
    return 0;
}