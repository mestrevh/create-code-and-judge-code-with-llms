/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        double sumX = 0, sumY = 0, sumXX = 0, sumYY = 0, sumXY = 0;
        for (int i = 0; i < n; ++i) {
            double x, y;
            cin >> x >> y;
            sumX += x;
            sumY += y;
            sumXX += x * x;
            sumYY += y * y;
            sumXY += x * y;
        }

        double num = (n * sumXY) - (sumX * sumY);
        double denA = (n * sumXX) - (sumX * sumX);
        double a = num / denA;
        double b = (sumY - a * sumX) / n;

        double denR = sqrt(denA * ((n * sumYY) - (sumY * sumY)));
        double r = num / denR;

        cout << fixed << setprecision(2);
        cout << "a = " << a << ", b = " << b << ", R = " << r << "\n";
    }

    return 0;
}

