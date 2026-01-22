/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<vector<int>> entros(N + 1, vector<int>(N + 1, 0));
        for (int i = 0; i < M; ++i) {
            int X, Y, Z;
            cin >> X >> Y >> Z;
            entros[X][Y] = Z;
            entros[Y][X] = Z;
        }
        int best = -1;
        int a1, a2, a3;
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                for (int k = j + 1; k <= N; ++k) {
                    int soma = entros[i][j] + entros[i][k] + entros[j][k];
                    if (soma > best) {
                        best = soma;
                        a1 = i;
                        a2 = j;
                        a3 = k;
                    }
                }
            }
        }
        cout << a1 << " " << a2 << " " << a3 << endl;
    }
    return 0;
}
