/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int M, N;
    char op;
    int X, Y;
    cin >> M >> op >> N;
    cin >> X >> op >> Y;

    vector<vector<int>> matriz(M, vector<int>(N));
    int produto = 1;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (op == '+') {
                matriz[i][j] = X * (i + 1) + Y * (j + 1);
            } else {
                matriz[i][j] = X * (i + 1) - Y * (j + 1);
            }
            if (i == j) {
                produto *= matriz[i][j];
            }
        }
    }

    cout << produto << endl;
    return 0;
}
