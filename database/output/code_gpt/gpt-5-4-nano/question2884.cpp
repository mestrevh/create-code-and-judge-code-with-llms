/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Digite a sequencia de numero:\n";
    vector<double> a(101);
    for (int i = 0; i < 101; i++) {
        if (!(cin >> a[i])) return 0;
    }

    double target = a[100];

    cout << "Indice no qual o numero desejado aparece:\n";
    bool printed = false;
    for (int i = 0; i < 100; i++) {
        if (a[i] == target) {
            cout << i << "\n";
            printed = true;
        }
    }
    return 0;
}