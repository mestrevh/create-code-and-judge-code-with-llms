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
    cout << "O numero digitado e ";
    cout << (n % 2 == 0 ? "par" : "impar");
    return 0;
}