/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> naves(N);
    int totalCapacity = 0;

    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        naves[i].resize(A, B);
        totalCapacity += A * B;
    }

    int pessoas;
    cin >> pessoas;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < naves[i].size(); ++j) {
            if (pessoas >= naves[i][j]) {
                cout << "Nave " << (i + 1) << " - Setor " << (j + 1) << ": " << naves[i][j] << " pessoa(s)" << endl;
                pessoas -= naves[i][j];
            } else {
                cout << "Nave " << (i + 1) << " - Setor " << (j + 1) << ": " << pessoas << " pessoa(s)" << endl;
                pessoas = 0;
            }
        }
    }

    cout << "Pessoas nao evacuadas: " << pessoas << " pessoa(s)" << endl;
    return 0;
}
