/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 6; ++i) {
        cout << "Digite pontuacao da partida " << i << ":" << "\n";
    }

    int scores[6];
    bool has_negative = false;
    long long total = 0;

    for (int i = 0; i < 6; ++i) {
        if (!(cin >> scores[i])) break;
        if (scores[i] < 0) {
            has_negative = true;
        }
        total += scores[i];
    }

    if (has_negative) {
        cout << "Valores negativos nao sao permitidos." << "\n";
    } else {
        cout << "Total de pontos: " << total << ". O competidor esta ";
        if (total >= 100) {
            cout << "classificado." << "\n";
        } else {
            cout << "desclassificado." << "\n";
        }
    }

    return 0;
}