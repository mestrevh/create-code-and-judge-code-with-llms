/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int n;
int subtree_size[MAXN];
long long total_dist = 0;
long long pairs_with_dist_d = 0;
int d = 0;

pair<int, int> bfs(int start) {
    vector<int> dist(n + 1, -1);
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

void dfs_size(int u, int p) {
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_size(v, u);
            total_dist += (long long)subtree_size[v] * (n - subtree_size[v]);
            subtree_size[u] += subtree_size[v];
        }
    }
}

vector<int> dfs_count_pairs(int u, int p) {
    vector<int> my_counts(d + 1, 0);
    my_counts[0] = 1;

    for (int v : adj[u]) {
        if (v != p) {
            vector<int> child_counts = dfs_count_pairs(v, u);
            
            for (size_t k1 = 0; k1 < child_counts.size(); ++k1) {
                if (child_counts[k1] == 0) continue;
                int k2 = d - (k1 + 1);
                if (k2 >= 0 && (size_t)k2 < my_counts.size()) {
                    pairs_with_dist_d += (long long)child_counts[k1] * my_counts[k2];
                }
            }

            for (size_t k1 = 0; k1 < child_counts.size(); ++k1) {
                if (k1 + 1 <= (size_t)d) {
                    my_counts[k1 + 1] += child_counts[k1];
                }
            }
        }
    }
    return my_counts;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n <= 1) {
        cout << 0 << endl;
        return 0;
    }

    pair<int, int> farthest_from_1 = bfs(1);
    int u = farthest_from_1.first;
    pair<int, int> diameter_pair = bfs(u);
    d = diameter_pair.second;

    dfs_size(1, 0);
    
    if (d > 0) {
        dfs_count_pairs(1, 0);
    }

    long long final_answer = total_dist - (pairs_with_dist_d * (long long)d);

    cout << final_answer << endl;

    return 0;
}
