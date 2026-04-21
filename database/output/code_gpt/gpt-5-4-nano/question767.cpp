/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    long long x;
    while (cin >> x) a.push_back(x);

    if (a.empty()) return 0;

    sort(a.begin(), a.end());
    int n = (int)a.size();

    cout << "Mediana = ";
    if (n % 2 == 1) {
        cout << a[n / 2];
    } else {
        long long left = a[n / 2 - 1];
        long long right = a[n / 2];
        double med = (left + right) / 2.0;
        cout << fixed << setprecision(1) << med;
    }
    return 0;
}