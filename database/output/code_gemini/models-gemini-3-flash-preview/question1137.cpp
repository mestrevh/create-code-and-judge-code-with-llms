/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <array>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef array<int, 8> State;

const int moves[10][2] = {
    {0, 1}, {1, 2}, {2, 3},
    {4, 5}, {5, 6}, {6, 7},
    {0, 4}, {1, 5}, {2, 6}, {3, 7}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    State start, target;
    for (int i = 0; i < 8; ++i) {
        if (!(cin >> start[i])) break;
    }
    for (int i = 0; i < 8; ++i) {
        if (!(cin >> target[i])) break;
    }

    if (start == target) {
        cout << 0 << endl;
        return 0;
    }

    priority_queue<pair<int, State>, vector<pair<int, State>>, greater<pair<int, State>>> pq;
    map<State, int> dist;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        State curr = pq.top().second;
        pq.pop();

        if (d > dist[curr]) continue;
        if (curr == target) {
            cout << d << endl;
            return 0;
        }

        for (int i = 0; i < 10; ++i) {
            int u = moves[i][0];
            int v = moves[i][1];
            
            int move_cost = curr[u] + curr[v];
            int next_d = d + move_cost;
            State next_s = curr;
            swap(next_s[u], next_s[v]);

            auto it = dist.find(next_s);
            if (it == dist.end() || it->second > next_d) {
                dist[next_s] = next_d;
                pq.push({next_d, next_s});
            }
        }
    }

    return 0;
}