/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> tabuleiro(n, vector<int>(n));
    int naviosContados = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tabuleiro[i][j];
            naviosContados += tabuleiro[i][j];
        }
    }

    if (naviosContados > k) {
        cout << "Defesa invalida!" << endl;
        return 0;
    }

    vector<pair<int, int>> ataques(2 * k);
    for (int i = 0; i < 2 * k; i++) {
        cin >> ataques[i].first >> ataques[i].second;
        if (atuacoes[i].first < 0 || ataques[i].first >= n || 
            ataques[i].second < 0 || ataques[i].second >= n) {
            cout << "Ataque invalido!" << endl;
            return 0;
        }
    }

    int naviosDestruídos = 0;
    for (auto ataque : ataques) {
        if (tabuleiro[ataque.first][ataque.second] == 1) {
            naviosDestruídos++;
            tabuleiro[ataque.first][ataque.second] = 0;
        }
    }

    if (naviosDestruídos == naviosContados) {
        cout << "Ataque venceu!" << endl;
    } else {
        cout << "Defesa venceu!" << endl;
    }

    return 0;
}
