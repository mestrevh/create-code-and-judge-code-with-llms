/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    double s;
    cin >> s;

    vector<double> b = a;
    for (double &x : b) x -= s / 2.0;

    sort(b.begin(), b.end());
    int i = 0, j = n - 1;
    while (i < j) {
        double sum = b[i] + b[j];
        if (fabs(sum) < 1e-9) {
            cout << "SIM";
            return 0;
        }
        if (sum < 0) i++;
        else j--;
    }
    cout << "NAO";
    return 0;
}