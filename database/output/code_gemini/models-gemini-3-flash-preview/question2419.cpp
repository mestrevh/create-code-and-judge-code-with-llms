/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double budget;
    while (cin >> budget) {
        string best_name;
        double best_price = 0.0;
        double best_cb = -1.0;
        bool found = false;

        for (int i = 0; i < 3; ++i) {
            string s;
            double p, n;
            if (!(cin >> s >> p >> n)) break;

            if (p <= budget) {
                double current_cb = n / p;
                bool update = false;

                if (!found) {
                    update = true;
                } else {
                    if (current_cb > best_cb + 1e-9) {
                        update = true;
                    } else if (abs(current_cb - best_cb) < 1e-9) {
                        if (p < best_price - 1e-9) {
                            update = true;
                        }
                        // Tie-break: if prices are also equal, the one that appeared first is kept.
                        // Since we only update if p < best_price, the first one is naturally prioritized.
                    }
                }

                if (update) {
                    best_name = s;
                    best_price = p;
                    best_cb = current_cb;
                    found = true;
                }
            }
        }

        if (found) {
            cout << "Comprarei o celular " << best_name << "\n";
        } else {
            cout << "O meu celular nem esta tao ruim assim" << "\n";
        }
    }

    return 0;
}