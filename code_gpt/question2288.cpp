/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> A(M, vector<int>(M));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    set<pair<int, int>> selected;
    bool bomb_found = false;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        if (selected.count({x, y})) {
            cout << "Essa casa ja foi selecionada.\n";
            continue;
        }

        int right_sum = 0, down_sum = 0, diag_sum = 0;

        for (int j = y; j < M; j++) right_sum += A[x][j]; // Soma à direita
        for (int j = x; j < M; j++) down_sum += A[j][y]; // Soma abaixo
        for (int j = x, k = y; j < M && k < M; j++, k++) diag_sum += A[j][k]; // Soma diagonal

        if (right_sum == down_sum && down_sum == diag_sum) {
            cout << "Bomba encontrada.\nVoce perdeu.\n";
            bomb_found = true;
            break;
        } else {
            A[x][y] = -1;
            selected.insert({x, y});
            cout << "Boa jogada, a casa (" << x << "," << y << ") nao tinha bomba.\n";
        }
    }

    if (!bomb_found) {
        cout << "Voce e uma pessoa de sorte.\n";
    }

    return 0;
}
