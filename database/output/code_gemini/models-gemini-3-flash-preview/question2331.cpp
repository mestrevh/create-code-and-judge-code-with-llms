/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>

using namespace std;

int grid[10][10];
bool visited[10][10];

// Ordem de checagem: Sul, Leste, Norte, Oeste
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool solve(int r, int c) {
    if (r == 9 && c == 9) return true;
    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        // Verifica limites da matriz, se é um túnel (1) e se ainda não foi visitado
        if (nr >= 0 && nr < 10 && nc >= 0 && nc < 10 && grid[nr][nc] == 1 && !visited[nr][nc]) {
            // Se o caminho recursivo encontrar a saída, retorna true imediatamente
            // Isso respeita a regra de não considerar outras direções se uma já funcionar
            if (solve(nr, nc)) return true;
        }
    }
    return false;
}

int main() {
    // Otimização de I/O padrão C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Frequência das respostas dos reféns
    map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        counts[x]++;
    }

    // Leitura da matriz 10x10 do labirinto
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
        }
    }

    // Um refém fala a verdade se a quantidade de pessoas que ele diz que fala a verdade
    // for exatamente igual ao número de pessoas que deram aquela mesma resposta.
    // k pessoas falam a verdade se e somente se exatamente k pessoas disseram o número k.
    bool truthFound = false;
    for (map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
        if (it->first > 0 && it->first == it->second) {
            truthFound = true;
            break;
        }
    }

    if (truthFound) {
        // String baseada nos casos de teste fornecidos
        cout << "Vamos nessa, temos que sair rapido..." << endl;
        
        // Inicia busca recursiva se a entrada do túnel estiver aberta
        if (grid[0][0] == 1 && solve(0, 0)) {
            cout << "Tudo nosso." << endl;
        } else {
            cout << "Continuem cavando!" << endl;
        }
    } else {
        cout << "Ja nao se pode confiar nos refens como antigamente..." << endl;
    }

    return 0;
}