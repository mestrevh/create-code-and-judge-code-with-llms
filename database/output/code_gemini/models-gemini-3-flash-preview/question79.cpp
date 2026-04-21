/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long k;
    while (cin >> k && k != 0) {
        long long mat[4][4];
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 4; ++i) {
                cin >> mat[i][j];
            }
        }

        for (int i = 0; i < 4; ++i) {
            mat[i][i] *= k;
        }

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}