/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5;
    int count = 0;
    for (int i = 0; i < n; i++) {
        double original, discounted;
        if (!(cin >> original)) return 0;
        cin >> discounted;
        if (discounted <= original * 0.8 + 1e-9) count++;
    }
    cout << count;
    return 0;
}