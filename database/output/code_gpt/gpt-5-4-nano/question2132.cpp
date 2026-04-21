/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> A(N), B(N);
    vector<int> totalCap(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        totalCap[i] = A[i] * B[i];
    }

    long long people;
    cin >> people;

    vector<vector<long long>> matrix(N);
    for (int i = 0; i < N; i++) matrix[i].assign(A[i], 0);

    for (int i = 0; i < N && people > 0; i++) {
        for (int j = 0; j < A[i] && people > 0; j++) {
            long long take = min<long long>(B[i], people);
            matrix[i][j] = take;
            people -= take;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < A[i]; j++) {
            cout << "Nave " << (i + 1) << " - Setor " << (j + 1) << ": " << matrix[i][j]
                 << " pessoa(s)\n";
        }
    }
    cout << "Pessoas nao evacuadas: " << people << " pessoa(s)";
    return 0;
}