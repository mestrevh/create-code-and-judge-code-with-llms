/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<double> a(5);
    for (int i = 0; i < 5; i++) {
        if (!(cin >> a[i])) return 0;
    }

    sort(a.begin(), a.end());
    double sum = a[1] + a[2] + a[3];

    cout.setf(ios::fixed);
    cout << setprecision(1) << sum << "\n";
    return 0;
}