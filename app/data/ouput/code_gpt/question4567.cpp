/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    
    if (M != A) {
        cout << "Nao eh possivel multiplicar!" << endl;
        return 0;
    }

    vector<vector<int>> matriz1(N, vector<int>(M));
    vector<vector<int>> matriz2(A, vector<int>(B));
    vector<vector<int>> resultado(N, vector<int>(B, 0));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> matriz1[i][j];

    for (int i = 0; i < A; ++i)
        for (int j = 0; j < B; ++j)
            cin >> matriz2[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < B; ++j)
            for (int k = 0; k < M; ++k)
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < B; ++j) {
            cout << resultado[i][j] << (j == B - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
