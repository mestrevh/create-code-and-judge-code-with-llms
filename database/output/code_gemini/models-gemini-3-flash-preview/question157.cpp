/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct State {
    int u, sa, sb;
};

bool visited[31][101][101];
int price[31];
char group[31];
vector<int> adj[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    if (!(cin >> N >> T)) return 0;

    for (int i = 0; i < N; ++i) {
        int x, p, k;
        char c;
        cin >> x >> p >> c >> k;
        price[x] = p;
        group[x] = c;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            adj[x].push_back(v);
        }
    }

    queue<State> q;
    q.push({0, 0, 0});
    visited[0][0][0] = true;

    int min_diff = 200; 

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.sa + curr.sb > 0) {
            int diff = curr.sa - curr.sb;
            if (diff < 0) diff = -diff;
            if (diff < min_diff) min_diff = diff;
        }

        int nsa = curr.sa;
        int nsb = curr.sb;
        if (group[curr.u] == 'A') nsa += price[curr.u];
        else nsb += price[curr.u];

        if (nsa + nsb <= T && !visited[curr.u][nsa][nsb]) {
            visited[curr.u][nsa][nsb] = true;
            q.push({curr.u, nsa, nsb});
        }

        for (int v : adj[curr.u]) {
            if (!visited[v][curr.sa][curr.sb]) {
                visited[v][curr.sa][curr.sb] = true;
                q.push({v, curr.sa, curr.sb});
            }
        }
    }

    cout << min_diff << endl;

    return 0;
}