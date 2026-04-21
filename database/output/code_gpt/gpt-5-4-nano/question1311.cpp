/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    switch (n) {
        case 1: cout << "Domingo"; break;
        case 2: cout << "Segunda"; break;
        case 3: cout << "Terca"; break;
        case 4: cout << "Quarta"; break;
        case 5: cout << "Quinta"; break;
        case 6: cout << "Sexta"; break;
        case 7: cout << "Sabado"; break;
        default: cout << "valor invalido";
    }
    return 0;
}