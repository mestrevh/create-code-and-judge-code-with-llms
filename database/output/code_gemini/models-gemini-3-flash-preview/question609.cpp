/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool dfs(int u, const vector<vector<int>>& adj, vector<int>& match, vector<bool>& vis) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            if (match[v] < 0 || dfs(match[v], adj, match, vis)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<vector<bool>> parent_has(N, vector<bool>(N + 1, false));
    vector<bool> parent_is_full(N, false);

    for (int i = 0; i < N; ++i) {
        int B;
        cin >> B;
        if (B == N) parent_is_full[i] = true;
        for (int j = 0; j < B; ++j) {
            int antigen;
            cin >> antigen;
            if (antigen >= 1 && antigen <= N) {
                parent_has[i][antigen] = true;
            }
        }
    }

    while (Q--) {
        int B;
        cin >> B;
        vector<int> target(B);
        for (int i = 0; i < B; ++i) {
            cin >> target[i];
        }

        if (B == 0) {
            bool possible = true;
            for (int i = 0; i < N; ++i) {
                if (parent_is_full[i]) {
                    possible = false;
                    break;
                }
            }
            cout << (possible ? "Y\n" : "N\n");
        } else {
            vector<vector<int>> adj(B);
            for (int i = 0; i < B; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (parent_is_full[j] || (target[i] >= 1 && target[i] <= N && parent_has[j][target[i]])) {
                        adj[i].push_back(j);
                    }
                }
            }

            int matching_size = 0;
            vector<int> match(N, -1);
            for (int i = 0; i < B; ++i) {
                vector<bool> vis(N, false);
                if (dfs(i, adj, match, vis)) {
                    matching_size++;
                }
            }

            if (matching_size == B) {
                cout << "Y\n";
            } else {
                cout << "N\n";
            }
        }
    }

    return 0;
}