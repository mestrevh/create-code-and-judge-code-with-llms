/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int idade;
    while (cin >> idade && idade != 0) {
        if (idade < 16) {
            if (idade < 0) cout << "Você ainda não nasceu.\n";
            else cout << "Você não pode votar.\n";
        } else if (idade >= 18 && idade <= 70) {
            cout << "Você tem a obrigatoriedade de votar.\n";
        } else {
            cout << "Na sua idade, o voto é opcional.\n";
        }
    }
    return 0;
}