/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Gift {
    int price;
    char group;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;

    vector<int> prices(N);
    vector<char> groups(N);
    vector<vector<int>> adj(N);

    for (int i = 0; i < N; ++i) {
        int id, p, k;
        char c;
        cin >> id >> p >> c >> k;
        prices[id] = p;
        groups[id] = c;
        for (int j = 0; j < k; ++j) {
            int neighbor;
            cin >> neighbor;
            adj[id].push_back(neighbor);
        }
    }

    vector<bool> reachable(N, false);
    queue<int> q;

    reachable[0] = true;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!reachable[v]) {
                reachable[v] = true;
                q.push(v);
            }
        }
    }

    vector<Gift> available_gifts;
    for (int i = 0; i < N; ++i) {
        if (reachable[i]) {
            available_gifts.push_back({prices[i], groups[i]});
        }
    }

    vector<vector<bool>> dp(T + 1, vector<bool>(T + 1, false));
    dp[0][0] = true;

    for (int total_cost = 1; total_cost <= T; ++total_cost) {
        for (int cost_A = 0; cost_A <= total_cost; ++cost_A) {
            int cost_B = total_cost - cost_A;
            
            for (const auto& gift : available_gifts) {
                if (dp[cost_A][cost_B]) {
                    break;
                }
                if (gift.group == 'A') {
                    if (cost_A >= gift.price && dp[cost_A - gift.price][cost_B]) {
                        dp[cost_A][cost_B] = true;
                    }
                } else {
                    if (cost_B >= gift.price && dp[cost_A][cost_B - gift.price]) {
                        dp[cost_A][cost_B] = true;
                    }
                }
            }
        }
    }

    int min_diff = INF;
    for (int cost_A = 0; cost_A <= T; ++cost_A) {
        for (int cost_B = 0; cost_B <= T; ++cost_B) {
            if (cost_A + cost_B > 0 && cost_A + cost_B <= T && dp[cost_A][cost_B]) {
                min_diff = min(min_diff, abs(cost_A - cost_B));
            }
        }
    }
    
    cout << min_diff << endl;

    return 0;
}
