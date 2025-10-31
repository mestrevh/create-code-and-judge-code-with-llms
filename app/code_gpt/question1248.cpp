/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int L, C;
    cin >> L >> C;
    vector<vector<string>> terreno(L, vector<string>(C));
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> terreno[i][j];
        }
    }
    int S;
    cin >> S;
    vector<pair<int, int>> areas(S);
    for (int i = 0; i < S; ++i) {
        int x, y;
        cin >> x >> y;
        areas[i] = {x - 1, y - 1};
    }

    int custoRepelente = 0, areasExcelentes = 0;

    for (const auto& area : areas) {
        int x = area.first, y = area.second;
        if (terreno[x][y] == "vermelho") {
            terreno[x][y] = "amarelo";
            custoRepelente += 3;
        } else if (terreno[x][y] == "amarelo") {
            terreno[x][y] = "verde";
        }
    }

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            if (terreno[i][j] == "verde") {
                areasExcelentes++;
            }
        }
    }

    int lucro = areasExcelentes * 4 - custoRepelente;

    if (lucro < 0) {
        cout << "prejuizo" << endl;
    } else {
        cout << lucro << endl;
    }

    return 0;
}
