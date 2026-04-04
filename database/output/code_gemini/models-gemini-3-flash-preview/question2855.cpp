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

    int n;
    cout << "Digite a dimensao da matriz quadrada N x N:\n";
    if (!(cin >> n)) return 0;

    vector<vector<long long>> mat(n, vector<long long>(n));
    cout << "Digite os elementos da matriz:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(cin >> mat[i][j])) break;
        }
    }

    if (n <= 0) return 0;

    long long target = 0;
    for (int j = 0; j < n; ++j) {
        target += mat[0][j];
    }

    bool is_magic = true;

    for (int i = 0; i < n; ++i) {
        long long s = 0;
        for (int j = 0; j < n; ++j) s += mat[i][j];
        if (s != target) {
            is_magic = false;
            break;
        }
    }

    if (is_magic) {
        for (int j = 0; j < n; ++j) {
            long long s = 0;
            for (int i = 0; i < n; ++i) s += mat[i][j];
            if (s != target) {
                is_magic = false;
                break;
            }
        }
    }

    if (is_magic) {
        long long d1 = 0, d2 = 0;
        for (int i = 0; i < n; ++i) {
            d1 += mat[i][i];
            d2 += mat[i][n - 1 - i];
        }
        if (d1 != target || d2 != target) {
            is_magic = false;
        }
    }

    if (is_magic) {
        cout << "Os elementos FORMAM um quadrado magico.\n";
        cout << "A soma do quadrado magico e " << target << ".\n";
    } else {
        cout << "Os elementos NAO FORMAM um quadrado magico.\n";
    }

    return 0;
}