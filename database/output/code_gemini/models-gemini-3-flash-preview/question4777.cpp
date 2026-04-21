/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    int year;
    while (cin >> c >> year) {
        if ((c == 'S' || c == 'P' || c == 'G') && (year > 2005)) {
            double s = 1.0, p = 0.0, g = 0.0;
            for (int i = 2005; i < year; ++i) {
                double ns = s * 0.5 + p * 0.0 + g * 1.0;
                double np = s * 0.25 + p * 0.0 + g * 0.0;
                double ng = s * 0.25 + p * 1.0 + g * 0.0;
                s = ns;
                p = np;
                g = ng;
            }

            string carName;
            double resultProb = 0.0;
            if (c == 'S') {
                carName = "Sedan";
                resultProb = s;
            } else if (c == 'P') {
                carName = "Palio";
                resultProb = p;
            } else {
                carName = "Gol";
                resultProb = g;
            }

            cout << "Probabilidade de ter um " << carName << " em " << year << ": " << fixed << setprecision(2) << (resultProb * 100.0) << "%\n";
        } else {
            cout << "Entrada inválida\n";
        }
    }

    return 0;
}