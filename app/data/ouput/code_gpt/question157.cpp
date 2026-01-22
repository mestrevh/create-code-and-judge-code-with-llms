/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

struct City {
    int price;
    char group;
    vector<int> roads;
};

vector<City> cities;
int N, T;
int dp[31][101][2];

void bfs(int start) {
    queue<tuple<int, int, int>> q; // (current city, current money, group)
    q.push({start, 0, 0});
    dp[start][0][0] = 0;
    dp[start][0][1] = 0;

    while (!q.empty()) {
        auto [current, money, group_sum] = q.front();
        q.pop();

        for (int i = 0; i < cities[current].roads.size(); i++) {
            int next = cities[current].roads[i];
            for (int p = 0; p <= T - money; p++) {
                if (p == 0) continue;

                int new_money = money + p;
                if (new_money > T) continue;
                
                if (cities[next].group == 'A') {
                    int new_group_sum = group_sum + cities[next].price;
                    if (dp[next][new_money][0] < new_group_sum) {
                        dp[next][new_money][0] = new_group_sum;
                        q.push({next, new_money, new_group_sum});
                    }
                } else {
                    int new_group_sum = group_sum - cities[next].price;
                    if (dp[next][new_money][1] > new_group_sum) {
                        dp[next][new_money][1] = new_group_sum;
                        q.push({next, new_money, new_group_sum});
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N >> T;
    cities.resize(N);
    memset(dp, -1, sizeof dp);

    for (int i = 0; i < N; ++i) {
        int K;
        cin >> cities[i].price >> cities[i].group >> K;
        cities[i].price = (cities[i].group == 'A') ? cities[i].price : -cities[i].price; 
        cities[i].roads.resize(K);
        for (int j = 0; j < K; ++j) {
            cin >> cities[i].roads[j];
        }
    }

    bfs(0);
    
    int min_diff = numeric_limits<int>::max();
    for (int j = 0; j <= T; j++) {
        if (dp[0][j][0] >= 0 || dp[0][j][1] >= 0) {
            int diff = abs(dp[0][j][0] + dp[0][j][1]);
            min_diff = min(min_diff, diff);
        }
    }
    cout << min_diff << endl;

    return 0;
}
