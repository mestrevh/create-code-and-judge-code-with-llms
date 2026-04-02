/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long M;
    if (!(cin >> M)) return 0;

    string names[] = {"Verde", "Vermelho", "Azul", "Amarelo"};
    double ratios[4];
    bool affordable[4] = {false, false, false, false};
    double max_r = -1.0;
    bool found_any = false;

    for (int i = 0; i < 4; ++i) {
        long long P, V;
        if (!(cin >> P >> V)) break;
        if (P <= M) {
            found_any = true;
            affordable[i] = true;
            ratios[i] = (double)V / P;
            if (ratios[i] > max_r) {
                max_r = ratios[i];
            }
        } else {
            affordable[i] = false;
            ratios[i] = -1.0;
        }
    }

    if (!found_any) {
        cout << "Acho que vou a pé :(" << endl;
    } else {
        bool verde_special_rule = false;
        if (affordable[0]) {
            if (max_r - ratios[0] <= 1.0000000001) {
                verde_special_rule = true;
            }
        }

        if (verde_special_rule) {
            cout << "Verde" << endl;
        } else {
            for (int i = 0; i < 4; ++i) {
                if (affordable[i] && (max_r - ratios[i] < 1e-11)) {
                    cout << names[i] << endl;
                    break;
                }
            }
        }
    }

    return 0;
}