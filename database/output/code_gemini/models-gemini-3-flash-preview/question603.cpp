/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, test_count = 1;
    while (cin >> n && n != 0) {
        map<string, int> name_to_id;
        vector<string> id_to_name(n);

        for (int i = 0; i < n; ++i) {
            cin >> id_to_name[i];
            name_to_id[id_to_name[i]] = i;
        }

        vector<vector<int>> adj(n);
        vector<int> in_degree(n, 0);

        for (int i = 0; i < n; ++i) {
            string u_name;
            int m;
            cin >> u_name >> m;
            int u = name_to_id[u_name];
            for (int j = 0; j < m; ++j) {
                string v_name;
                cin >> v_name;
                int v = name_to_id[v_name];
                adj[v].push_back(u);
                in_degree[u]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        vector<string> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(id_to_name[u]);

            for (int v : adj[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        cout << "Teste " << test_count++ << "\n";
        if ((int)result.size() == n) {
            for (int i = 0; i < n; ++i) {
                cout << result[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "impossivel\n";
        }
        cout << "\n";
    }

    return 0;
}