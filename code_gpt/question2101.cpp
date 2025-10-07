/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> matriz(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matriz[i][j];

    for (int i = 0; i < K; i++) {
        string comando;
        int A, B;
        cin >> comando >> A >> B;
        if (comando == "ataque") {
            swap(matriz[A - 1], matriz[B - 1]);
        } else if (comando == "defesa") {
            for (int j = 0; j < N; j++)
                swap(matriz[j][A - 1], matriz[j][B - 1]);
        }
    }

    int I, J;
    cin >> I >> J;

    cout << matriz[I - 1][J - 1] << endl;

    return 0;
}
