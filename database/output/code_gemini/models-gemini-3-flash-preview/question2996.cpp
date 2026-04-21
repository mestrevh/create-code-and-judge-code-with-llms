/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double val;
    while (cin >> val) {
        // Convert to cents using floor(x + 0.5) for rounding precision
        long long cents = (long long)floor(val * 100.0 + 0.5);

        // Validation: 0.70 <= cost <= 6.20 and must be multiple of 0.10
        if (cents < 70 || cents > 620 || cents % 10 != 0) {
            cout << "Preco invalido, refaca a leitura do pacote." << endl;
        } else {
            // Convert to units of 10 cents to simplify calculations
            int cp = (int)(cents / 10);
            int bestX = -1;
            int bestY = -1;

            // Find the combination that minimizes total stamps (X + Y)
            // Minimizing X + Y for 50X + 20Y = C is achieved by maximizing X
            for (int x = cp / 5; x >= 0; --x) {
                int remainder = cp - 5 * x;
                if (remainder >= 0 && remainder % 2 == 0) {
                    bestX = x;
                    bestY = remainder / 2;
                    break;
                }
            }

            if (bestX != -1) {
                cout << "Compre " << bestX << " selo(s) de R$ 0.50 e " << bestY << " selo(s) de R$ 0.20!" << endl;
                // Exit after the first valid input is successfully processed
                break;
            } else {
                // This part should technically not be reached given 70 <= cents <= 620
                cout << "Preco invalido, refaca a leitura do pacote." << endl;
            }
        }
    }

    return 0;
}