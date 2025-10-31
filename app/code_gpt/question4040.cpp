/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    char foco;
    cin >> N >> foco;
    vector<pair<string, vector<vector<int>>>> formacoes(N);

    for (int i = 0; i < N; ++i) {
        string formacao;
        for (int j = 0; j < 4; ++j) {
            vector<int> linha(6);
            for (int k = 0; k < 6; ++k) {
                cin >> linha[k];
            }
            if (j > 0) formacao += "-";
            formacao += to_string(linha[0] + linha[1] + linha[2] + linha[3] + linha[4] + linha[5]);
            formacoes[i].second.push_back(linha);
        }
        formacoes[i].first = formacao;
    }

    int melhorIndex = -1;
    int maiorQtd = -1;

    for (int i = 0; i < N; ++i) {
        int qtd = 0;
        if (foco == 'A') qtd = formacoes[i].second[0][0] + formacoes[i].second[0][1] + formacoes[i].second[0][2] + formacoes[i].second[0][3];
        else if (foco == 'M') qtd = formacoes[i].second[1][0] + formacoes[i].second[1][1] + formacoes[i].second[1][2] + formacoes[i].second[1][3];
        else if (foco == 'D') qtd = formacoes[i].second[2][0] + formacoes[i].second[2][1] + formacoes[i].second[2][2] + formacoes[i].second[2][3] + formacoes[i].second[2][4] + formacoes[i].second[2][5];

        if (qtd > maiorQtd) {
            maiorQtd = qtd;
            melhorIndex = i;
        }
    }

    cout << "Pipi e Mariozito deviam escolher a formacao " << formacoes[melhorIndex].first << endl;
    for (const auto &linha : formacoes[melhorIndex].second) {
        for (int j = 0; j < 6; ++j) {
            cout << linha[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
