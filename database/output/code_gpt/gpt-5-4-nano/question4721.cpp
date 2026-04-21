/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long somar_lista(const vector<long long>& numeros) {
    long long soma = 0;
    for (long long num : numeros) soma += num;
    return soma;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> numeros;
    long long x;
    while (cin >> x) numeros.push_back(x);

    cout << somar_lista(numeros) << "\n";
    return 0;
}