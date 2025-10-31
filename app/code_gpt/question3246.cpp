/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

class Graph {
public:
    int V;
    unordered_map<int, vector<int>> adj;
    vector<int> degree;

    Graph(int V) {
        this->V = V;
        degree.resize(V, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    bool isEulerian() {
        int odd = 0;
        for (int i = 0; i < V; i++) {
            if (degree[i] % 2 != 0) odd++;
        }
        return odd == 0; // Eulerian circuit
    }

    void eulerianPath() {
        if (!isEulerian()) {
            cout << "No" << endl;
            return;
        }

        stack<int> st;
        vector<int> path;
        int start = 0;

        for (int i = 0; i < V; i++) {
            if (!adj[i].empty()) {
                start = i;
                break;
            }
        }
        
        st.push(start);
        while (!st.empty()) {
            int u = st.top();
            if (adj[u].empty()) {
                path.push_back(u);
                st.pop();
            } else {
                int v = adj[u].back();
                adj[u].pop_back();
                adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
                st.push(v);
            }
        }
        
        cout << "Yes" << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << (i == 0 ? "" : " ");
        }
        cout << endl;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    Graph g(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.eulerianPath();
    return 0;
}
