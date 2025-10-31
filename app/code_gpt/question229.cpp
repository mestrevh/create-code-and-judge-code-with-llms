/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, V, G;
    cin >> N >> M >> V >> G;
    
    vector<vector<int>> campo(N, vector<int>(M, 0));
    
    for (int i = 0; i < V; i++) {
        int y, x;
        cin >> y >> x;
        campo[y][x] = 1;
    }

    auto printCampo = [&](const vector<vector<int>>& campo) {
        for (const auto& linha : campo) {
            cout << ' ';
            for (int estado : linha) {
                cout << estado << ' ';
            }
            cout << endl;
        }
        cout << endl;
    };

    printCampo(campo);

    for (int geração = 0; geração < G; geração++) {
        vector<vector<int>> novoCampo(N, vector<int>(M, 0));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int vizinhosVivos = 0;
                
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                            vizinhosVivos += campo[ni][nj];
                        }
                    }
                }
                
                if (campo[i][j] == 1) {
                    if (vizinhosVivos < 2 || vizinhosVivos > 3) {
                        novoCampo[i][j] = 0;
                    } else {
                        novoCampo[i][j] = 1;
                    }
                } else {
                    if (vizinhosVivos == 3) {
                        novoCampo[i][j] = 1;
                    }
                }
            }
        }
        
        campo = novoCampo;
        printCampo(campo);
    }

    return 0;
}
