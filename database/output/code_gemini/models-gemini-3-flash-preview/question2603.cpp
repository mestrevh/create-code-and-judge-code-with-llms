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

    int M, N;
    if (!(cin >> M >> N)) return 0;

    vector<vector<char>> grid(M, vector<char>(N));
    int currR = -1, currC = -1;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!(cin >> grid[i][j])) break;
            if (grid[i][j] == 'E') {
                currR = i;
                currC = j;
            }
        }
    }

    int prevR = -1, prevC = -1;
    // Ordem de prioridade: acima, a direita, abaixo e a esquerda
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    bool found = false;
    while (currR != -1 && currC != -1) {
        int nextR = -1, nextC = -1;
        bool moved = false;

        for (int i = 0; i < 4; i++) {
            int nr = currR + dr[i];
            int nc = currC + dc[i];

            if (nr >= 0 && nr < M && nc >= 0 && nc < N) {
                // Regra: sem voltar atrás
                if (nr == prevR && nc == prevC) continue;

                if (grid[nr][nc] == 'S') {
                    found = true;
                    moved = true;
                    break;
                } else if (grid[nr][nc] == '*') {
                    nextR = nr;
                    nextC = nc;
                    moved = true;
                    break;
                }
            }
        }

        if (found || !moved) break;

        prevR = currR;
        prevC = currC;
        currR = nextR;
        currC = nextC;
    }

    if (found) {
        cout << "Esse Yordle é confiável, vamos por esse atalho." << endl;
    } else {
        cout << "Não tem saída, deve ser a LeBlanc tentando me enganar, melhor dar o fora daqui." << endl;
    }

    return 0;
}