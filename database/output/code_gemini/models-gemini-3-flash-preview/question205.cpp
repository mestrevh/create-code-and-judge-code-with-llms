/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;
vector<int> adj[MAXN];
int dist[MAXN];

pair<int, int> bfs(int start, int n) {
    for (int i = 1; i <= n; ++i) dist[i] = -1;
    queue<int> q;
    
    q.push(start);
    dist[start] = 0;
    
    int farthest_node = start;
    int max_dist = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (dist[u] > max_dist) {
            max_dist = dist[u];
            farthest_node = u;
        }
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return {farthest_node, max_dist};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    pair<int, int> p1 = bfs(1, n);
    pair<int, int> p2 = bfs(p1.first, n);
    
    cout << p2.second << endl;
    
    return 0;
}