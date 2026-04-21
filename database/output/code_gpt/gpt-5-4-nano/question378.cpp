/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long sum = 0, x;
    for (int i = 0; i < 6; i++) {
        if (!(cin >> x)) return 0;
        sum += x;
    }
    cout << (sum >= 100 ? "Classificado" : "Eliminado");
    return 0;
}