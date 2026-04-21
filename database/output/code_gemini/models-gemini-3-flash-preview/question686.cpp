/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long total_moves = 0;
    for (int i = 0; i < N - 1; ++i) {
        int diff = M - H[i];
        total_moves += abs(diff);
        H[i] += diff;
        H[i + 1] += diff;
    }

    cout << total_moves << endl;

    return 0;
}

