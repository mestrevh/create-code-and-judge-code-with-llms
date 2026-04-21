/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    double n;
    cout << "Digite um numero: ";
    if (!(cin >> n)) return 0;

    if (n > 0) cout << "\nO numero e positivo";
    else if (n < 0) cout << "\nO numero e negativo";
    else cout << "\nO numero e nulo";
    return 0;
}