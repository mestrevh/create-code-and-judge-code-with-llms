/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int countNeg = 0;
    for (int i = 0; i < 5; i++) {
        double a;
        cout << "Digite um valor:\n";
        if (!(cin >> a)) return 0;
        if (a < 0) countNeg++;
    }
    cout << "Foram digitados " << countNeg << " numeros negativos";
    return 0;
}