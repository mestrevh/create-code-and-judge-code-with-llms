/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool eh_bissexto(int ano) {
    if (ano % 400 == 0) return true;
    if (ano % 100 == 0) return false;
    return ano % 4 == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ano;
    if (!(cin >> ano)) return 0;
    cout << (eh_bissexto(ano) ? "bissexto" : "nao bissexto");
    return 0;
}