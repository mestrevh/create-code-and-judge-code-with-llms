/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    long long min_total_time = numeric_limits<long long>::max();
    int winner_index = -1;

    for (int i = 1; i <= N; ++i) {
        long long current_competitor_sum = 0;
        for (int j = 0; j < M; ++j) {
            long long lap_time;
            cin >> lap_time;
            current_competitor_sum += lap_time;
        }

        if (current_competitor_sum < min_total_time) {
            min_total_time = current_competitor_sum;
            winner_index = i;
        }
    }

    cout << winner_index << endl;

    return 0;
}