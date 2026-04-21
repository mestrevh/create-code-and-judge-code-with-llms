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

    long double sumX = 0, sumY = 0, sumXX = 0, sumXY = 0;
    for (int i = 0; i < n; i++) {
        long double x, y;
        cin >> x >> y;
        sumX += x;
        sumY += y;
        sumXX += x * x;
        sumXY += x * y;
    }

    long double denom = n * sumXX - sumX * sumX;
    long double A = 0, B = 0;

    if (fabsl(denom) < 1e-18) {
        A = 0;
        B = sumY / n;
    } else {
        A = (n * sumXY - sumX * sumY) / denom;
        B = (sumY - A * sumX) / n;
    }

    cout.setf(ios::fixed);
    cout << setprecision(2);
    cout << "A: " << (double)A << "\n";
    cout << "B: " << (double)B << "\n";
    return 0;
}