/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long soma = 0;
    for (int i = 0; i <= 500; i += 2) soma += i;
    cout << "Soma dos pares de 0 a 500: " << soma;
    return 0;
}