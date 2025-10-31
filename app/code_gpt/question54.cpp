/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M && (N || M)) {
        vector<vector<int>> e(N+1, vector<int>(N+1, 0));
        for (int i = 0; i < M; ++i) {
            int X, Y, Z;
            cin >> X >> Y >> Z;
            e[X][Y] = Z;
            e[Y][X] = Z;
        }
        int best_sum = -1;
        int b1=0, b2=0, b3=0;
        for (int i = 1; i <= N; ++i) {
            for (int j = i+1; j <= N; ++j) {
                for (int k = j+1; k <= N; ++k) {
                    int sum = e[i][j] + e[i][k] + e[j][k];
                    if (sum > best_sum || (sum == best_sum && make_tuple(i,j,k) < make_tuple(b1,b2,b3))) {
                        best_sum = sum;
                        b1 = i; b2 = j; b3 = k;
                    }
                }
            }
        }
        cout << b1 << " " << b2 << " " << b3 << endl;
    }
    return 0;
}
