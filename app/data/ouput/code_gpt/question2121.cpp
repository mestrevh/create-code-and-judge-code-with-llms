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
        areas[i] = {x - 1, y - 1}; // ajustando para índice 0
    }
    
    int custos = 0;
    for (const auto& area : areas) {
        int x = area.first, y = area.second;
        if (terreno[x][y] == "vermelho") {
            terreno[x][y] = "amarelo"; // transforma vermelho em amarelo
            custos += 3; // custo do repelente
        }
    }
    
    int colheita = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            if (terreno[i][j] == "verde") {
                colheita += 4; // 4 Galeões por área cultivada
            } else if (terreno[i][j] == "amarelo") {
                terreno[i][j] = "verde"; // transforma amarelo em verde
                colheita += 4; // colheita dessa área agora é possível
            }
        }
    }
    
    int lucro = colheita - custos;
    if (lucro > 0) {
        cout << lucro << endl;
    } else {
        cout << "prejuizo" << endl;
    }
    
    return 0;
}
