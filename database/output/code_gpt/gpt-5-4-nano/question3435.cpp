/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

vector<double> readVector(int n) {
    vector<double> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    return v;
}

double dotProduct(const vector<double>& a, const vector<double>& b) {
    int n = (int)a.size();
    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += a[i] * b[i];
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<double> a = readVector(n);
    vector<double> b = readVector(n);

    double ans = dotProduct(a, b);
    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}