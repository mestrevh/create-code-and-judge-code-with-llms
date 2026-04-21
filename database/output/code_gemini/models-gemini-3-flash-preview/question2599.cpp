/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string months[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    string ordinals[] = {"Primeiro", "Segundo", "Terceiro", "Quarto"};
    string days[] = {"Sabado", "Domingo"};

    double min_prob = 2.0;
    bool found = false;
    int res_m = -1, res_w = -1, res_d = -1;

    for (int m = 0; m < 12; ++m) {
        for (int w = 0; w < 4; ++w) {
            for (int d = 0; d < 2; ++d) {
                double p;
                if (!(cin >> p)) break;
                if (p <= 0.5) {
                    if (!found || p < min_prob - 1e-9) {
                        min_prob = p;
                        res_m = m;
                        res_w = w;
                        res_d = d;
                        found = true;
                    }
                }
            }
        }
    }

    if (!found) {
        cout << "Proximo ano eu tento denovo..." << endl;
    } else {
        cout << "O melhor dia e no " << ordinals[res_w] << " " << days[res_d] << " de " << months[res_m] << endl;
    }

    return 0;
}