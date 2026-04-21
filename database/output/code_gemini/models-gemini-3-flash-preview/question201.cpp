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

    vector<pair<long long, int>> results(N);

    for (int i = 0; i < N; ++i) {
        long long total_time = 0;
        for (int j = 0; j < M; ++j) {
            long long lap_time;
            cin >> lap_time;
            total_time += lap_time;
        }
        results[i] = {total_time, i + 1};
    }

    sort(results.begin(), results.end());

    if (N >= 1) cout << results[0].second << "\n";
    if (N >= 2) cout << results[1].second << "\n";
    if (N >= 3) cout << results[2].second << "\n";

    return 0;
}

