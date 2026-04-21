/*
Código criado pelo models/gemini-3.1-pro-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (cin >> N >> M) {
        vector<int> houses(N);
        for (int i = 0; i < N; ++i) {
            cin >> houses[i];
        }

        long long total_time = 0;
        int current_index = 0;

        for (int i = 0; i < M; ++i) {
            int target;
            cin >> target;
            int target_index = lower_bound(houses.begin(), houses.end(), target) - houses.begin();
            total_time += abs(current_index - target_index);
            current_index = target_index;
        }

        cout << total_time << "\n";
    }
    return 0;
}