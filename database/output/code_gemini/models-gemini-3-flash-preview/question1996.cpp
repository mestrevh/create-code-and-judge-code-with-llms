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

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0) {
        cout << "AZUL" << endl;
        return 0;
    }

    vector<vector<char>> mat(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(cin >> mat[i][j])) break;
        }
    }

    // 1. BRANCO: Guardas (g) nas colunas pares e populares (p) nas colunas ímpares.
    // Interpretando como 1-indexação (Coluna 1=ímpar, 2=par, etc).
    bool c1 = true;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if ((j + 1) % 2 == 0) { // Par (índices 1, 3, 5...)
                if (mat[i][j] != 'g') c1 = false;
            } else { // Ímpar (índices 0, 2, 4...)
                if (mat[i][j] != 'p') c1 = false;
            }
        }
    }

    // 2. AMARELO: Dois ou mais suspeitos (s) em qualquer uma das linhas.
    bool c2 = false;
    for (int i = 0; i < n; ++i) {
        int suspects = 0;
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 's') suspects++;
        }
        if (suspects >= 2) {
            c2 = true;
            break;
        }
    }

    // 3. LARANJA: Pelo menos um inimigo (i) em qualquer das diagonais (principal ou secundária).
    bool c3 = false;
    for (int i = 0; i < n; ++i) {
        if (mat[i][i] == 'i' || mat[i][n - 1 - i] == 'i') {
            c3 = true;
            break;
        }
    }

    // 4. VERMELHO: Quantidade de inimigos (i) e suspeitos (s) > guardas (g) nas cercanias (bordas).
    int is_count = 0, g_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                if (mat[i][j] == 'i' || mat[i][j] == 's') {
                    is_count++;
                } else if (mat[i][j] == 'g') {
                    g_count++;
                }
            }
        }
    }
    bool c4 = (is_count > g_count);

    // Relatório final
    if (!c1 && !c2 && !c3 && !c4) {
        cout << "AZUL" << endl;
    } else {
        if (c1) cout << "BRANCO" << endl; else cout << "TRANSPARENTE" << endl;
        if (c2) cout << "AMARELO" << endl; else cout << "TRANSPARENTE" << endl;
        if (c3) cout << "LARANJA" << endl; else cout << "TRANSPARENTE" << endl;
        if (c4) cout << "VERMELHO" << endl; else cout << "TRANSPARENTE" << endl;
    }

    return 0;
}