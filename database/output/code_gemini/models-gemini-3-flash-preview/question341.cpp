/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    double discounts[] = {25.0, 20.0, 18.0, 15.0, 12.0, 10.0};

    for (int i = 0; i < n; ++i) {
        int d;
        double p;
        if (!(cin >> d >> p)) break;

        for (int y = 0; y < 3; ++y) {
            double r = 0;
            if (d >= 0 && d <= 5) {
                r = discounts[d];
            }

            if (p <= 100.0) {
                r /= 2.0;
            }

            if (p > 45.0) {
                double drop = p * (r / 100.0);
                p -= drop;
                if (p < 45.0) {
                    p = 45.0;
                }
            }
        }

        cout << "Jogo[" << i << "] = R$" << fixed << setprecision(2) << p << "\n";
    }

    return 0;
}