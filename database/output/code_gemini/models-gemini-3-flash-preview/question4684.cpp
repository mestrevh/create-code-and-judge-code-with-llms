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
    long long X;
    if (!(cin >> N >> M >> X)) return 0;

    vector<int> counts(M, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            long long val;
            cin >> val;
            if (val == X) {
                counts[j]++;
            }
        }
    }

    int max_count = 0;
    for (int j = 0; j < M; ++j) {
        cout << counts[j] << (j == M - 1 ? " " : " ");
        if (counts[j] > max_count) {
            max_count = counts[j];
        }
    }
    cout << "\n\n";

    for (int r = 0; r < max_count; ++r) {
        for (int c = 0; c < M; ++c) {
            if (r < counts[c]) {
                cout << 1;
            } else {
                cout << 0;
            }
            if (c < M - 1) cout << " ";
        }
        cout << " \n";
    }

    return 0;
}