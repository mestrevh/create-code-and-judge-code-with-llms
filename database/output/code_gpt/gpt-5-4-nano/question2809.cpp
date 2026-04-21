/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cout << "Digite um numero: ";
    if (!(cin >> n)) return 0;
    long long unidades = n % 10;
    cout << "\nAlgarismo das unidades: " << unidades;
    return 0;
}