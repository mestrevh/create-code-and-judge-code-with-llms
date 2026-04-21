/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mat[6][6];

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (!(cin >> mat[i][j])) break;
        }
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            int val;
            if (!(cin >> val)) break;
            cout << mat[i][j] + val << (j == 5 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}