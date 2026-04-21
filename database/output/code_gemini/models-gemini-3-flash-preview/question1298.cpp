/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
char grid[11][11];
bool visited[11][11];
int max_score = 0;

/**
 * Funcao para retornar o valor de cada tesouro com base no caractere.
 */
inline int get_treasure_value(char c) {
    if (c == 'b') return 1;
    if (c == 'p') return 5;
    if (c == 'o') return 10;
    if (c == 'd') return 50;
    return 0;
}

/**
 * Backtracking (DFS) para encontrar o caminho simples que maximize a pontuacao.
 * Um caminho simples nao visita a mesma celula mais de uma vez.
 */
void dfs(int r, int c, int current_score) {
    if (current_score > max_score) {
        max_score = current_score;
    }

    static const int dr[] = {-1, 1, 0, 0};
    static const int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        // Verifica limites do mapa, se ja foi visitado e se nao e parede
        if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc] && grid[nr][nc] != '#') {
            visited[nr][nc] = true;
            dfs(nr, nc, current_score + get_treasure_value(grid[nr][nc]));
            // Backtracking: desmarca a celula como visitada para permitir outros caminhos
            visited[nr][nc] = false;
        }
    }
}

int main() {
    // Otimizacao de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Leitura das dimensoes do labirinto
    if (!(cin >> N >> M)) return 0;

    // Leitura do grid e inicializacao da matriz de visitados
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    // Inicia a busca a partir da posicao (0,0) se ela for acessivel
    if (N > 0 && M > 0 && grid[0][0] != '#') {
        visited[0][0] = true;
        dfs(0, 0, get_treasure_value(grid[0][0]));
    }

    // Saida da maior pontuacao encontrada
    cout << max_score << endl;

    return 0;
}