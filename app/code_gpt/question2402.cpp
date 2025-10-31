/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> M(N);
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    int max_sum = 0, current_sum = 0;
    int start = 0, best_start = 0, best_end = 0;
    bool in_interval = false;

    for (int i = 1; i < N; i++) {
        if (M[i] > M[i - 1]) {
            if (!in_interval) {
                start = i - 1;
                current_sum = M[i - 1];
                in_interval = true;
            }
            current_sum += M[i];
        } else {
            if (in_interval) {
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    best_start = start;
                    best_end = i - 1;
                }
                in_interval = false;
            }
        }
    }

    if (in_interval && current_sum > max_sum) {
        max_sum = current_sum;
        best_start = start;
        best_end = N - 1;
    }

    cout << best_start + 1 << " " << best_end + 1 << " " << max_sum << endl;
    return 0;
}
