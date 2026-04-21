/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<double> a(10);
    for (int i = 0; i < 10; i++) {
        if (!(cin >> a[i])) return 0;
    }

    cout.setf(ios::fixed);
    cout << setprecision(1);
    for (int i = 9; i >= 0; i--) {
        if (i != 9) cout << "\n";
        cout << a[i];
    }
    return 0;
}