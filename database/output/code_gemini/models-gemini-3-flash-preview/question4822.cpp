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

    int N;
    if (!(cin >> N)) return 0;

    vector<vector<int>> mat(N, vector<int>(N));
    vector<vector<bool>> mark(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mat[i][j];
        }
    }

    bool changed = false;

    // Check rows for horizontal disturbing blocks
    for (int i = 0; i < N; ++i) {
        int j = 0;
        while (j < N) {
            int val = mat[i][j];
            int start = j;
            while (j < N && mat[i][j] == val) {
                j++;
            }
            if (val != 0 && (j - start) >= 3) {
                changed = true;
                for (int k = start; k < j; ++k) {
                    mark[i][k] = true;
                }
            }
        }
    }

    // Check columns for vertical disturbing blocks
    for (int j = 0; j < N; ++j) {
        int i = 0;
        while (i < N) {
            int val = mat[i][j];
            int start = i;
            while (i < N && mat[i][j] == val) {
                i++;
            }
            if (val != 0 && (i - start) >= 3) {
                changed = true;
                for (int k = start; k < i; ++k) {
                    mark[k][j] = true;
                }
            }
        }
    }

    if (!changed) {
        cout << "Os dados estão estáveis. Continue refinando." << endl;
    } else {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (mark[i][j]) {
                    cout << 0;
                } else {
                    cout << mat[i][j];
                }
                if (j < N - 1) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}