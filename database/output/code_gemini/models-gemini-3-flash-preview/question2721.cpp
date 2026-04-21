/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, C;
    if (!(cin >> L >> C)) {
        return 0;
    }

    int mat[26][26];

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            if (!(cin >> mat[i][j])) break;
        }
    }

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            int val;
            if (!(cin >> val)) break;
            mat[i][j] += val;
        }
    }

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << mat[i][j] << (j == C - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}