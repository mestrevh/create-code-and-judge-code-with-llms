/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int hasB[505][505];
int hasW[505][505];
int fW[505][505];
int fB[505][505];
int fAny[505][505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, P;
    if (!(cin >> N >> P)) return 0;

    for (int i = 0; i < P; ++i) {
        int r, c;
        cin >> r >> c;
        if (r >= 1 && r <= N && c >= 1 && c <= N) {
            hasB[r][c] = 1;
        }
    }
    for (int i = 0; i < P; ++i) {
        int r, c;
        cin >> r >> c;
        if (r >= 1 && r <= N && c >= 1 && c <= N) {
            hasW[r][c] = 1;
        }
    }

    long long ansB = 0;
    long long ansW = 0;

    for (int i = N; i >= 1; --i) {
        for (int j = N; j >= 1; --j) {
            if (hasW[i][j]) {
                fW[i][j] = 0;
            } else {
                fW[i][j] = 1 + min({fW[i+1][j], fW[i][j+1], fW[i+1][j+1]});
            }

            if (hasB[i][j]) {
                fB[i][j] = 0;
            } else {
                fB[i][j] = 1 + min({fB[i+1][j], fB[i][j+1], fB[i+1][j+1]});
            }

            if (hasB[i][j] || hasW[i][j]) {
                fAny[i][j] = 0;
            } else {
                fAny[i][j] = 1 + min({fAny[i+1][j], fAny[i][j+1], fAny[i+1][j+1]});
            }

            ansB += (fW[i][j] - fAny[i][j]);
            ansW += (fB[i][j] - fAny[i][j]);
        }
    }

    cout << ansB << " " << ansW << endl;

    return 0;
}