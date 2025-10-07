/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_x2 += x * x;
    }

    double A = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double B = (sum_y - A * sum_x) / n;

    cout << fixed << setprecision(2);
    cout << "A: " << A << "\nB: " << B << endl;

    return 0;
}
