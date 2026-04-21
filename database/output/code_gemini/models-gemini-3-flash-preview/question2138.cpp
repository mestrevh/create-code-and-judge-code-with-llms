/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    if (!(cin >> n >> m)) return 0;

    if (m <= 0) return 0;

    long long r = n / m;
    if (r <= 0) return 0;

    for (long long j = 0; j < m; ++j) {
        for (long long i = 0; i < r; ++i) {
            if (i > 0) cout << " ";
            // The original matrix A[i][j] has R rows and M columns.
            // The k-th even number is at A[i][j] where k = i * M + j + 1.
            // The transpose B[j][i] is A[i][j].
            // We iterate through j (new rows) and i (new columns).
            cout << 2 * (i * m + j + 1);
        }
        cout << "\n";
    }

    return 0;
}