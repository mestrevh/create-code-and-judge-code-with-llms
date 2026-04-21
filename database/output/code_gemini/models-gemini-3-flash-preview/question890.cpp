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

    int L, C, N;
    if (!(cin >> L >> C >> N)) return 0;

    long long total_elements = (long long)L * C;
    vector<int> mat(total_elements);
    for (long long i = 0; i < total_elements; ++i) {
        cin >> mat[i];
    }

    int k = (N % 4 + 4) % 4;

    if (k == 0) {
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < C; ++j) {
                if (j > 0) cout << ' ';
                cout << mat[(long long)i * C + j];
            }
            cout << '\n';
        }
    } else if (k == 1) {
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < L; ++j) {
                if (j > 0) cout << ' ';
                cout << mat[(long long)(L - 1 - j) * C + i];
            }
            cout << '\n';
        }
    } else if (k == 2) {
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < C; ++j) {
                if (j > 0) cout << ' ';
                cout << mat[(long long)(L - 1 - i) * C + (C - 1 - j)];
            }
            cout << '\n';
        }
    } else if (k == 3) {
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < L; ++j) {
                if (j > 0) cout << ' ';
                cout << mat[(long long)j * C + (C - 1 - i)];
            }
            cout << '\n';
        }
    }

    return 0;
}