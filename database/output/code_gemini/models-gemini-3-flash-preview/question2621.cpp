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

    int T;
    if (!(cin >> T)) return 0;

    if (T <= 0) return 0;

    vector<vector<long long>> mat(T, vector<long long>(T));
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < T; ++j) {
            long long val;
            cin >> val;
            if (val < 0) {
                val *= 2;
            }
            mat[i][j] = val;
        }
    }

    for (int j = 0; j < T; ++j) {
        for (int i = 0; i < T; ++i) {
            cout << mat[i][j] << (i == T - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}

