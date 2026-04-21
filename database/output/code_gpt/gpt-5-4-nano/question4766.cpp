/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x, soma = 0;
    while (cin >> x) {
        if (x == 0) break;
        if (x > 0) soma += x;
    }
    cout << "A soma dos valores eh: " << soma << "\n";
    return 0;
}