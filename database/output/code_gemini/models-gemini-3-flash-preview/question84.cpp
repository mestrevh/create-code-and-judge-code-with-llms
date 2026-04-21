/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int counts[4][5][5];
    for (int t = 1; t <= 3; ++t) {
        for (int i = 1; i <= 4; ++i) {
            for (int j = 1; j <= 4; ++j) {
                counts[t][i][j] = 0;
            }
        }
    }

    int bh_count = 0;
    int bus_special = 0;

    int o, d, t;
    while (cin >> o >> d >> t && (o != 0 || d != 0 || t != 0)) {
        if (o >= 1 && o <= 4 && d >= 1 && d <= 4 && t >= 1 && t <= 3) {
            counts[t][o][d]++;
            if (o == 1) {
                bh_count++;
            }
            if (t == 3 && o == 4 && (d == 2 || d == 4)) {
                bus_special++;
            }
        }
    }

    const char* labels[] = {"", "Automovel:", "Caminhao:", "Onibus:"};

    for (int v = 1; v <= 3; ++v) {
        cout << labels[v] << "\n";
        for (int i = 1; i <= 4; ++i) {
            for (int j = 1; j <= 4; ++j) {
                cout << counts[v][i][j] << " ";
            }
            cout << "\n";
        }
    }

    cout << "Origem Belo Horizonte: " << bh_count << "\n";
    cout << "Onibus: Brasilia - Petropolis ou Barbacena: " << bus_special << "\n";

    return 0;
}