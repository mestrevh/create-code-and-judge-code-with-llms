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

    int I, J;
    if (!(cin >> I >> J)) return 0;

    vector<long long> col_sums(J, 0);
    long long diag_sum = 0;

    for (int i = 0; i < I; ++i) {
        long long row_sum = 0;
        for (int j = 0; j < J; ++j) {
            long long val;
            if (!(cin >> val)) break;
            row_sum += val;
            col_sums[j] += val;
            if (i == j) {
                diag_sum += val;
            }
        }
        cout << "Linha " << i << ": " << row_sum << "\n";
    }

    for (int j = 0; j < J; ++j) {
        cout << "Coluna " << j << ": " << col_sums[j] << "\n";
    }

    if (I == J) {
        cout << "Diagonal principal: " << diag_sum << "\n";
    }

    return 0;
}