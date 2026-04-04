/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<int>> mat(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> mat[i][j];
        }
    }

    const string off_msg = "Queria que todo mundo fosse assim";
    const string on_msg = "Desliga o farol cidadao ( ._.)";

    for (int j = 0; j < M; ++j) {
        if (j % 2 == 0) {
            for (int i = 0; i < N; ++i) {
                if (mat[i][j] == 0) {
                    cout << off_msg << "\n";
                } else {
                    cout << on_msg << "\n";
                }
            }
        } else {
            for (int i = N - 1; i >= 0; --i) {
                if (mat[i][j] == 0) {
                    cout << off_msg << "\n";
                } else {
                    cout << on_msg << "\n";
                }
            }
        }
    }

    return 0;
}