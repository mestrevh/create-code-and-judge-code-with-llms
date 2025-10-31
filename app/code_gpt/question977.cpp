/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Event {
    int t, m, index;
};

bool compare(const Event &a, const Event &b) {
    return a.index > b.index;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<Event> events(N);
    for (int i = 0; i < N; i++) {
        cin >> events[i].t >> events[i].m;
        events[i].index = i;
    }

    vector<vector<int>> dp(K + 1, vector<int>(N + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        int t = events[i].t, m = events[i].m;
        for (int j = 0; j <= K; j++) {
            dp[j][i + 1] = min(dp[j][i + 1], dp[j][i]); 
            if (j + m <= K) {
                dp[j + m][i + 1] = min(dp[j + m][i + 1], dp[j][i] + t);
            }
        }
    }

    int minSadness = INT_MAX, bestFear = -1;
    for (int j = 0; j <= K; j++) {
        if (dp[j][N] < minSadness) {
            minSadness = dp[j][N];
            bestFear = j;
        }
    }

    vector<int> chosenEvents;
    for (int i = N, j = bestFear; i > 0; i--) {
        if (dp[j][i] != dp[j][i - 1]) {
            chosenEvents.push_back(events[i - 1].index);
            j -= events[i - 1].m;
        }
    }

    sort(chosenEvents.begin(), chosenEvents.end());

    cout << minSadness << " " << bestFear << endl;
    for (int i = 0; i < chosenEvents.size(); i++) {
        cout << chosenEvents[i];
        if (i < chosenEvents.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
