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

const int INF = 0x3f3f3f3f;

struct Edge {
    int to;
    int len;
    int first;
};

struct State {
    int d, u, c;
    bool operator>(const State& other) const {
        return d > other.d;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    while (cin >> M && M != 0) {
        string O_str, D_str;
        cin >> O_str >> D_str;

        map<string, int> lang_to_id;
        int idCount = 0;
        
        auto getId = [&](const string& s) {
            auto it = lang_to_id.find(s);
            if (it == lang_to_id.end()) {
                return lang_to_id[s] = idCount++;
            }
            return it->second;
        };

        int startId = getId(O_str);
        int destId = getId(D_str);

        // Max possible languages is 2 * M + 2
        vector<vector<Edge>> adj(2 * M + 5);
        for (int i = 0; i < M; ++i) {
            string u_str, v_str, w_str;
            cin >> u_str >> v_str >> w_str;
            int u = getId(u_str);
            int v = getId(v_str);
            int len = (int)w_str.length();
            int first = (int)(w_str[0] - 'a');
            adj[u].push_back({v, len, first});
            adj[v].push_back({u, len, first});
        }

        // dist[lang_id][last_char_idx], 26 means "no previous char"
        vector<vector<int>> dist(idCount, vector<int>(27, INF));
        priority_queue<State, vector<State>, greater<State>> pq;

        // Initialize Dijkstra from start language
        dist[startId][26] = 0;
        pq.push({0, startId, 26});

        int ans = -1;
        while (!pq.empty()) {
            State top = pq.top();
            pq.pop();

            int d = top.d;
            int u = top.u;
            int c = top.c;

            if (d > dist[u][c]) continue;
            
            // If we reached the destination language, it's the shortest path
            if (u == destId) {
                ans = d;
                break;
            }

            for (const auto& edge : adj[u]) {
                // Rule: consecutive words cannot have the same first letter
                if (edge.first != c) {
                    if (dist[edge.to][edge.first] > d + edge.len) {
                        dist[edge.to][edge.first] = d + edge.len;
                        pq.push({dist[edge.to][edge.first], edge.to, edge.first});
                    }
                }
            }
        }

        if (ans == -1) {
            cout << "impossivel\n";
        } else {
            cout << ans << "\n";
        }
    }

    return 0;
}