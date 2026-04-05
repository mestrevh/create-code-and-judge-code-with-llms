/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Structure to store road information
struct Edge {
    int u, v;
    string u_name, v_name;
};

int N, M;
int edge_count[105][105];
bool is_pair_critical[105][105];
int visited[105];
int vis_token;
int q[105];
vector<int> distinct_adj[105];

/**
 * Checks if start_node can reach the capital (ID 0) after removing 
 * one instance of the edge between skip_u and skip_v.
 * Uses BFS for reachability check.
 */
bool can_reach(int start_node, int skip_u, int skip_v) {
    if (start_node == 0) return true;
    vis_token++;
    int h = 0, t = 0;
    q[t++] = start_node;
    visited[start_node] = vis_token;
    
    while (h < t) {
        int u = q[h++];
        for (int v : distinct_adj[u]) {
            int c = edge_count[u][v];
            // If this is the pair we are temporarily removing/skipping
            if (u == skip_u && v == skip_v) c--;
            
            if (c > 0) {
                // If we reach the capital, we're done
                if (v == 0) return true;
                if (visited[v] != vis_token) {
                    visited[v] = vis_token;
                    q[t++] = v;
                }
            }
        }
    }
    return false;
}

void solve() {
    // Standard IO optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N >> M && (N || M)) {
        map<string, int> name_to_id;
        for (int i = 0; i < N; i++) {
            string name;
            cin >> name;
            name_to_id[name] = i;
        }

        // Reset data structures for each test case
        for (int i = 0; i < N; i++) {
            distinct_adj[i].clear();
            visited[i] = 0;
            for (int j = 0; j < N; j++) {
                edge_count[i][j] = 0;
                is_pair_critical[i][j] = false;
            }
        }
        vis_token = 0;

        vector<Edge> input_edges;
        input_edges.reserve(M);
        for (int i = 0; i < M; i++) {
            string u_n, v_n;
            cin >> u_n >> v_n;
            int u = name_to_id[u_n];
            int v = name_to_id[v_n];
            input_edges.push_back({u, v, u_n, v_n});
            
            // Manage unique adjacency list and edge counts (handles multi-edges)
            if (edge_count[u][v] == 0) {
                distinct_adj[u].push_back(v);
            }
            edge_count[u][v]++;
        }

        // Determine if an edge between any pair (u, v) is critical.
        // A segment is critical if its removal makes the capital unreachable from its start node.
        for (int u = 0; u < N; u++) {
            // Capital (ID 0) always "reaches" itself
            if (u == 0) continue; 
            for (int v : distinct_adj[u]) {
                // If there's more than one segment between u and v, 
                // removing one doesn't break connectivity.
                if (edge_count[u][v] == 1) {
                    is_pair_critical[u][v] = !can_reach(u, u, v);
                }
            }
        }

        bool found_any = false;
        // Output critical segments in the order they appeared in the input
        for (int i = 0; i < M; i++) {
            if (is_pair_critical[input_edges[i].u][input_edges[i].v]) {
                cout << input_edges[i].u_name << " " << input_edges[i].v_name << "\n";
                found_any = true;
            }
        }

        if (!found_any) {
            cout << "Nenhuma\n";
        }
        // Requirement: print a blank line after each test case
        cout << "\n";
    }
}

int main() {
    solve();
    return 0;
}