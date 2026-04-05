/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<double> a;
    a.reserve(max(0, N));

    double x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        a.push_back(x);
    }

    if (N == 0) {
        cout << "Nenhuma nota informada!";
        return 0;
    }

    cout << "[";
    for (int i = 0; i < N; i++) {
        if (i) cout << ", ";
        cout << fixed << setprecision(1) << a[i];
    }
    cout << "]\n";

    double sum = 0.0;
    for (double v : a) sum += v;

    cout << fixed << setprecision(2) << sum;
    return 0;
}