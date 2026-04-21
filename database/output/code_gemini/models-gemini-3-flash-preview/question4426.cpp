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

    int K;
    if (!(cin >> K)) return 0;

    while (K--) {
        int N;
        if (!(cin >> N)) break;

        if (N <= 0) {
            continue;
        }

        vector<long long> row_sums(N, 0);
        vector<long long> col_sums(N, 0);
        long long diag1 = 0;
        long long diag2 = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                long long val;
                cin >> val;
                row_sums[i] += val;
                col_sums[j] += val;
                if (i == j) {
                    diag1 += val;
                }
                if (i + j == N - 1) {
                    diag2 += val;
                }
            }
        }

        long long target = row_sums[0];
        bool is_magic = true;

        for (int i = 0; i < N; ++i) {
            if (row_sums[i] != target) {
                is_magic = false;
                break;
            }
        }

        if (is_magic) {
            for (int j = 0; j < N; ++j) {
                if (col_sums[j] != target) {
                    is_magic = false;
                    break;
                }
            }
        }

        if (is_magic) {
            if (diag1 != target || diag2 != target) {
                is_magic = false;
            }
        }

        if (is_magic) {
            cout << "Eh quadrado magico!!!\n";
        } else {
            cout << "Nao eh!!!\n";
        }
    }

    return 0;
}