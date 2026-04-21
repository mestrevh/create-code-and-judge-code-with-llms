/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<double> a(7);
    for (int i = 0; i < 7; i++) {
        if (!(cin >> a[i])) return 0;
    }

    cout << "[";
    for (int i = 0; i < 7; i++) {
        if (i) cout << ", ";
        cout << a[i];
    }
    cout << "]";
    return 0;
}