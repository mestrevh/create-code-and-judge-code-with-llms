/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S, caseNum = 0;
    while (cin >> N >> S) {
        vector<vector<int>> adj(N);
        for (int i = 0; i < N; ++i) {
            int K;
            if (!(cin >> K)) break;
            adj[i].reserve(K);
            for (int j = 0; j < K; ++j) {
                int neighbor;
                if (cin >> neighbor) {
                    adj[i].push_back(neighbor);
                }
            }
        }

        vector<int> dist(N, -1);
        queue<int> q;

        dist[S] = 0;
        q.push(S);

        int maxDist = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (dist[u] > maxDist) maxDist = dist[u];
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        vector<int> countAtDist(maxDist + 1, 0);
        for (int i = 0; i < N; ++i) {
            if (dist[i] != -1) {
                countAtDist[dist[i]]++;
            }
        }

        cout << "caso " << caseNum++ << ":";
        int cumulative = 0;
        for (int i = 0; i <= maxDist; ++i) {
            cumulative += countAtDist[i];
            cout << " " << cumulative;
        }
        cout << "\n\n";
    }

    return 0;
}

