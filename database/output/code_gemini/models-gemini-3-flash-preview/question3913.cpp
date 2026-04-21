/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long aliado[4];
    long long inimigo_base[4];
    long long reforco[4];
    long long inimigo_total[4];

    for (int i = 0; i < 4; ++i) {
        if (!(cin >> aliado[i])) return 0;
    }
    for (int i = 0; i < 4; ++i) {
        if (!(cin >> inimigo_base[i])) return 0;
    }
    for (int i = 0; i < 4; ++i) {
        if (!(cin >> reforco[i])) return 0;
        inimigo_total[i] = inimigo_base[i] + reforco[i];
    }

    int count_aliado = 0;
    int count_inimigo = 0;

    for (int i = 0; i < 4; ++i) {
        if (aliado[i] > inimigo_total[i]) {
            count_aliado++;
        } else if (inimigo_total[i] > aliado[i]) {
            count_inimigo++;
        }
    }

    if (count_aliado > 2) {
        cout << "Avancar" << endl;
    } else if (count_inimigo > 2) {
        cout << "Recuar" << endl;
    } else {
        cout << "Permanecer" << endl;
    }

    return 0;
}