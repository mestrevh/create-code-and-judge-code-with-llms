/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int last_time[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N && N != 0) {
        long long total_presses = 0;
        vector<int> used;
        used.reserve(N);
        for (int T = 0; T < N; ++T) {
            int K;
            cin >> K;
            if (K > 1000000) {
                // Should not happen based on constraints, but for safety
                total_presses += (long long)K + T;
            } else {
                if (last_time[K] == 0) {
                    total_presses += (long long)K + T;
                } else {
                    total_presses += (long long)1 + (T - (last_time[K] - 1));
                }
                last_time[K] = T + 1;
                used.push_back(K);
            }
        }
        cout << total_presses << "\n";
        for (int k : used) {
            if (k <= 1000000) {
                last_time[k] = 0;
            }
        }
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

// The logic used treats each command by its identity (its initial position P_i).
// When a command K is executed at time T (where T is the number of previous commands executed):
// 1. If K is being executed for the first time:
//    Its current position in the history is its initial position plus the number
//    of commands added to the front so far (which is T).
// 2. If K has been executed before:
//    Its most recent occurrence was moved to the top (position 1) at time T_last.
//    Since then, (T - T_last) additional commands have been added to the front.
//    So its current position is 1 + (T - T_last).

// Global array to store the last time (T+1) each command was executed.
// Using T+1 allows 0 to represent "never executed".
int last_time_history[1000001];

int solve() {
    int N;
    while (cin >> N && N != 0) {
        long long total_presses = 0;
        vector<int> used;
        used.reserve(N);
        for (int T = 0; T < N; ++T) {
            int K;
            cin >> K;
            // The position in the history is the number of '↑' presses.
            if (last_time_history[K] == 0) {
                // Command K is executed for the first time.
                total_presses += (long long)K + T;
            } else {
                // Command K was last moved to the top at time last_time_history[K]-1.
                int T_last = last_time_history[K] - 1;
                total_presses += (long long)1 + (T - T_last);
            }
            // Update the last execution time and track K to reset it later.
            last_time_history[K] = T + 1;
            used.push_back(K);
        }
        cout << total_presses << "\n";
        // Reset the last_time_history array for only the commands used in this case.
        for (int k : used) {
            last_time_history[k] = 0;
        }
    }
    return 0;
}

// Final check: the problem asks to print just the total number for each case.
// O(N) complexity per case ensures it passes within the 2.0s time limit.