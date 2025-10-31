/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const long long INF = 1e18;
const int MAXS = 10005;

vector<pair<int, int>> adj[MAXS];
int s, t;

// Component processing variables
int visited[MAXS];
int component_id[MAXS];
int current_component_id = 0;

// Cycle finding variables
int parent[MAXS];
long long dist_from_dfs_start[MAXS];
bool on_stack[MAXS];
vector<int> component_nodes_temp;
vector<int> cycle_nodes_temp;
long long cycle_len_temp;
bool cycle_found_temp;

// Precomputed data for components with cycles
vector<long long> component_cycle_len;
vector<vector<int>> component_cycle_nodes_list;
int root[MAXS];
long long dist_to_cycle[MAXS];
long long max_branch_len[MAXS];

void find_longest_path_in_branch(int u, int p, long long current_dist, long long& max_dist, const vector<bool>& is_cycle_node) {
    max_dist = max(max_dist, current_dist);
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p && !is_cycle_node[v]) {
            find_longest_path_in_branch(v, u, current_dist + w, max_dist, is_cycle_node);
        }
    }
}


void dfs_cycle_find(int u, int p, long long current_dist) {
    visited[u] = 1;
    on_stack[u] = true;
    parent[u] = p;
    dist_from_dfs_start[u] = current_dist;
    component_nodes_temp.push_back(u);

    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v == p) continue;
        if (on_stack[v]) {
            if (!cycle_found_temp) {
                cycle_found_temp = true;
                cycle_len_temp = current_dist - dist_from_dfs_start[v] + w;
                cycle_nodes_temp.push_back(v);
                int curr = u;
                while (curr != v) {
                    cycle_nodes_temp.push_back(curr);
                    curr = parent[curr];
                }
            }
        } else if (!visited[v]) {
            dfs_cycle_find(v, u, current_dist + w);
        }
    }
    on_stack[u] = false;
}

void precompute() {
    fill(visited + 1, visited + s + 1, 0);
    fill(max_branch_len + 1, max_branch_len + s + 1, 0);
    component_cycle_len.push_back(0); 
    component_cycle_nodes_list.push_back({});

    for (int i = 1; i <= s; ++i) {
        if (!visited[i]) {
            current_component_id++;
            component_nodes_temp.clear();
            cycle_nodes_temp.clear();
            cycle_len_temp = 0;
            cycle_found_temp = false;

            dfs_cycle_find(i, 0, 0);

            for (int node : component_nodes_temp) {
                component_id[node] = current_component_id;
            }

            if (!cycle_found_temp) {
                 component_cycle_len.push_back(-1);
                 component_cycle_nodes_list.push_back({});
            } else {
                component_cycle_len.push_back(cycle_len_temp);
                component_cycle_nodes_list.push_back(cycle_nodes_temp);

                vector<bool> is_cycle_node(s + 1, false);
                for (int node : cycle_nodes_temp) {
                    is_cycle_node[node] = true;
                }

                queue<int> q;
                fill(dist_to_cycle + 1, dist_to_cycle + s + 1, -1);
                
                for (int node : cycle_nodes_temp) {
                    q.push(node);
                    dist_to_cycle[node] = 0;
                    root[node] = node;
                }

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (auto& edge : adj[u]) {
                        int v = edge.first;
                        int w = edge.second;
                        if (dist_to_cycle[v] == -1) {
                            dist_to_cycle[v] = dist_to_cycle[u] + w;
                            root[v] = root[u];
                            q.push(v);
                        }
                    }
                }
                
                for (int u : cycle_nodes_temp) {
                     for (auto& edge : adj[u]) {
                        int v = edge.first;
                        int w = edge.second;
                        if (!is_cycle_node[v]) {
                            long long max_d_from_v = 0;
                            find_longest_path_in_branch(v, u, 0, max_d_from_v, is_cycle_node);
                            max_branch_len[u] = max(max_branch_len[u], (long long)w + max_d_from_v);
                        }
                    }
                }
            }
        }
    }
}


void solve() {
    int x;
    long long m;
    cin >> x >> m;

    int comp_id = component_id[x];
    long long c_len = component_cycle_len[comp_id];

    if (c_len == -1) {
        cout << -1 << "\n";
        return;
    }

    long long min_l = INF;
    long long d = dist_to_cycle[x];
    long long l_base = 2 * d + c_len;

    if (m <= c_len) {
        if (l_base >= m) {
            min_l = min(min_l, l_base);
        }
        for(int u : component_cycle_nodes_list[comp_id]){
            long long mbl = max_branch_len[u];
            if (mbl > 0) {
                long long l_excursion = l_base + 2 * mbl;
                if (m <= 2 * mbl && l_excursion >= m) {
                    min_l = min(min_l, l_excursion);
                }
            }
        }
    }

    if (min_l == INF) {
        cout << -1 << "\n";
    } else {
        cout << min_l << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    for (int i = 0; i < t; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    precompute();

    int q;
    cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}
