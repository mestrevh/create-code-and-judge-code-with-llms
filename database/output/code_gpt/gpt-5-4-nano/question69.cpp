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
    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    while (cin >> n) {
        if (n == 0) break;

        long double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;
        for (int i = 0; i < n; i++) {
            long double x, y;
            cin >> x >> y;
            sumX += x;
            sumY += y;
            sumXY += x * y;
            sumX2 += x * x;
            sumY2 += y * y;
        }

        long double denomA = n * sumX2 - sumX * sumX;
        long double a = 0, b = 0;

        if (fabsl(denomA) > 0) {
            a = (n * sumXY - sumX * sumY) / denomA;
            b = (sumY - a * sumX) / n;
        } else {
            a = 0;
            b = sumY / n;
        }

        long double numerR = n * sumXY - sumX * sumY;
        long double denomR = sqrt((n * sumX2 - sumX * sumX) * (n * sumY2 - sumY * sumY));

        long double R = 0;
        if (denomR != 0) R = numerR / denomR;

        if (R > 0 && R < 0.005L) R = 0;
        if (R < 0 && R > -0.005L) R = 0;

        cout << "a = " << (double)a << ", b = " << (double)b << ", R = " << (double)R << "\n";
    }
    return 0;
}