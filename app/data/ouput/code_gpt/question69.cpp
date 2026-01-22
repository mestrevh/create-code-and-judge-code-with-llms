/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<double> x(n), y(n);
        double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
            sumX += x[i];
            sumY += y[i];
            sumXY += x[i] * y[i];
            sumX2 += x[i] * x[i];
        }

        double a = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
        double b = (sumY - a * sumX) / n;

        double sumY2 = 0, sumResiduals = 0;
        for (int i = 0; i < n; ++i) {
            sumY2 += (y[i] - (a * x[i] + b)) * (y[i] - (a * x[i] + b));
            sumResiduals += (y[i] - (sumY / n)) * (y[i] - (sumY / n));
        }
        double R = sqrt(1 - (sumY2 / sumResiduals));

        cout << fixed << setprecision(2) << "a = " << a << ", b = " << b << ", R = " << R << endl;
    }
    return 0;
}
