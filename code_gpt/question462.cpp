/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> adj[50001];
int disc[50001], low[50001], parent[50001];
bool visited[50001];
int timeCounter, criticalCount;

void dfs(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++timeCounter;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= disc[u] && parent[u] != -1) {
                criticalCount++;
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findCriticalPlaces(int N) {
    timeCounter = 0;
    criticalCount = 0;
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        int S;
        while (cin >> S && S != 0) {
            int neighbor;
            while (cin >> neighbor) {
                adj[S].push_back(neighbor);
                adj[neighbor].push_back(S);
            }
        }
        findCriticalPlaces(N);
        cout << criticalCount << endl;
    }
    return 0;
}
