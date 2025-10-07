/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int N, K;
        cin >> N >> K;
        vector<int> pos(N);
        for (int i = 0; i < N; ++i) {
            cin >> pos[i];
        }

        sort(pos.begin(), pos.end());

        int max_count = 0;
        int best_position = numeric_limits<int>::max();

        for (int i = 0; i < N; ++i) {
            int current_position = pos[i];
            int left_bound = current_position - K;
            int right_bound = current_position + K;

            int count = upper_bound(pos.begin(), pos.end(), right_bound) - lower_bound(pos.begin(), pos.end(), left_bound);
            
            if (count > max_count || (count == max_count && current_position < best_position)) {
                max_count = count;
                best_position = current_position;
            }
        }

        cout << best_position << endl;
    }
    return 0;
}
