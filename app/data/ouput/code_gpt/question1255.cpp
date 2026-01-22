/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
};

int main() {
    int N, E, S, M;
    cin >> N >> E >> S >> M;

    vector<int> recovery(N);
    for (int i = 0; i < N; ++i) {
        cin >> recovery[i];
    }

    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v});
    }

    vector<int> minTime(N, INT_MAX);
    minTime[E] = 0;
    queue<int> q;
    q.push(E);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (const auto& edge : graph[current]) {
            int next = edge.to;
            int time = minTime[current] + 1;
            int waitTime = time % recovery[next];

            if (waitTime == 0) {
                time += recovery[next];
            } else if (waitTime <= 1) {
                time += 1 + (recovery[next] - waitTime);
            }

            if (time < minTime[next]) {
                minTime[next] = time;
                q.push(next);
            }
        }
    }

    if (minTime[S] == INT_MAX) {
        cout << "Araragi morreu\n";
    } else {
        cout << minTime[S] << " minutos\n";
    }
    
    return 0;
}
