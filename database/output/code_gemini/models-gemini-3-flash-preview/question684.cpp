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

    vector<int> houses(N);
    for (int i = 0; i < N; ++i) {
        cin >> houses[i];
    }

    long long total_time = 0;
    int current_idx = 0;

    for (int i = 0; i < M; ++i) {
        int target_house;
        cin >> target_house;

        // Since house numbers are strictly increasing, use binary search to find target index
        auto it = lower_bound(houses.begin(), houses.end(), target_house);
        int target_idx = (int)(it - houses.begin());

        int travel = target_idx - current_idx;
        if (travel < 0) travel = -travel;

        total_time += (long long)travel;
        current_idx = target_idx;
    }

    cout << total_time << "\n";

    return 0;
}