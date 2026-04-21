/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Digite os 10 numeros inteiros:\n";
    vector<int> a(10);
    for (int i = 0; i < 10; i++) cin >> a[i];

    cout << "Numeros pares na ordem inversa:\n";
    bool first = true;
    for (int i = 9; i >= 0; i--) {
        if (a[i] % 2 == 0) {
            if (!first) cout << ' ';
            cout << a[i];
            first = false;
        }
    }
    if (!first) cout << '\n';
    return 0;
}