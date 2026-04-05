/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<int>> field(N, vector<int>(M));
    int max_sum = 0;

    for (int i = 0; i < N; ++i) {
        int current_row_sum = 0;
        for (int j = 0; j < M; ++j) {
            cin >> field[i][j];
            current_row_sum += field[i][j];
        }
        if (current_row_sum > max_sum) {
            max_sum = current_row_sum;
        }
    }

    for (int j = 0; j < M; ++j) {
        int current_col_sum = 0;
        for (int i = 0; i < N; ++i) {
            current_col_sum += field[i][j];
        }
        if (current_col_sum > max_sum) {
            max_sum = current_col_sum;
        }
    }

    cout << max_sum << endl;

    return 0;
}