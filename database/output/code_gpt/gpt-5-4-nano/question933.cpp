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

    double sum = 0.0;
    vector<double> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
    }

    double media = sum / N;

    double bestVal = a[0];
    double bestDiff = fabs(a[0] - media);
    for (int i = 1; i < N; i++) {
        double d = fabs(a[i] - media);
        if (d < bestDiff) {
            bestDiff = d;
            bestVal = a[i];
        }
    }

    cout << fixed << setprecision(2);
    cout << "MEDIA: " << media << "\n";
    cout << "MAIS PROXIMO: " << bestVal << "\n";
    cout << "DIFERENCA: " << bestDiff << "\n";

    return 0;
}