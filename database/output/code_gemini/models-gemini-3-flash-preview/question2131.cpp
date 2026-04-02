/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P, E;
    if (!(cin >> P >> E)) return 0;

    // Obrigatoriamente armazenar em array bidimensional
    vector<vector<int>> matrizVotos(E, vector<int>(P));

    // Bloco de repetição para receber os votos
    for (int i = 0; i < E; ++i) {
        for (int j = 0; j < P; ++j) {
            cin >> matrizVotos[i][j];
        }
    }

    // Bloco de repetição diferente para apurá-los
    for (int j = 0; j < P; ++j) {
        int totalVotos = 0;
        for (int i = 0; i < E; ++i) {
            totalVotos += matrizVotos[i][j];
        }
        cout << "Princesa " << (j + 1) << ": " << totalVotos << " voto(s)\n";
    }

    return 0;
}