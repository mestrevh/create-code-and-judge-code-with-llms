/*
Código criado pelo gpt-4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        
        vector<vector<int>> entrosamento(N + 1, vector<int>(N + 1, 0));
        
        for (int i = 0; i < M; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            entrosamento[x][y] = z;
            entrosamento[y][x] = z;
        }
        
        int max_soma = 0;
        vector<int> melhor_banda(3);
        
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                for (int k = j + 1; k <= N; ++k) {
                    int soma = entrosamento[i][j] + entrosamento[i][k] + entrosamento[j][k];
                    if (soma > max_soma) {
                        max_soma = soma;
                        melhor_banda = {i, j, k};
                    } else if (soma == max_soma) {
                        vector<int> nova_banda = {i, j, k};
                        if (nova_banda < melhor_banda) {
                            melhor_banda = nova_banda;
                        }
                    }
                }
            }
        }
        
        cout << melhor_banda[0] << " " << melhor_banda[1] << " " << melhor_banda[2] << endl;
    }
    return 0;
}