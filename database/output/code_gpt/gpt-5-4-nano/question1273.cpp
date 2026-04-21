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

    vector<vector<int>> a(N, vector<int>(N));
    int val = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = val++;
        }
    }

    cout << "Matriz:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << a[i][j];
        }
        cout << "\n";
    }

    cout << "\nDiagonal Principal:\n";
    for (int i = 0; i < N; i++) {
        cout << setw(3 * i + 3) << a[i][i] << "\n";
    }

    cout << "\nDiagonal Secundaria:\n";
    for (int i = 0; i < N; i++) {
        int j = N - 1 - i;
        cout << setw(3 * (N - 1 - i) + 3) << a[i][j] << "\n";
    }

    return 0;
}