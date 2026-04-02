/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    if (!(cin >> L)) return 0;
    
    if (L <= 0) {
        // A 0x0 matrix is vacuously a magic square by definition.
        cout << "A matriz e magica" << endl;
        return 0;
    }

    vector<long long> row_sums(L, 0);
    vector<long long> col_sums(L, 0);
    long long diag1 = 0;
    long long diag2 = 0;

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j) {
            long long val;
            if (!(cin >> val)) break;
            row_sums[i] += val;
            col_sums[j] += val;
            if (i == j) {
                diag1 += val;
            }
            if (i + j == L - 1) {
                diag2 += val;
            }
        }
    }

    long long target = row_sums[0];
    bool is_magic = true;

    if (diag1 != target || diag2 != target) {
        is_magic = false;
    } else {
        for (int i = 0; i < L; ++i) {
            if (row_sums[i] != target || col_sums[i] != target) {
                is_magic = false;
                break;
            }
        }
    }

    if (is_magic) {
        cout << "A matriz e magica" << endl;
    } else {
        cout << "A matriz nao e magica" << endl;
    }

    return 0;
}