/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

const int MAXN = 50001;
vector<int> adj[MAXN];
int disc[MAXN], low[MAXN], parent[MAXN];
bool is_ap[MAXN];
int timer;

void find_ap(int u) {
    disc[u] = low[u] = timer++;
    int children = 0;

    for (int v : adj[u]) {
        if (v == parent[u]) {
            continue;
        }

        if (disc[v] != -1) {
            low[u] = min(low[u], disc[v]);
        } else {
            children++;
            parent[v] = u;
            find_ap(v);

            low[u] = min(low[u], low[v]);

            if (parent[u] == 0 && children > 1) {
                is_ap[u] = true;
            }
            if (parent[u] != 0 && low[v] >= disc[u]) {
                is_ap[u] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N && N != 0) {
        for (int i = 1; i <= N; ++i) {
            adj[i].clear();
            disc[i] = -1;
            parent[i] = 0;
            is_ap[i] = false;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string line;
        while (getline(cin, line)) {
            stringstream ss(line);
            int u;
            ss >> u;
            if (u == 0) {
                break;
            }
            int v;
            while (ss >> v) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        timer = 0;
        for (int i = 1; i <= N; ++i) {
            if (disc[i] == -1) {
                find_ap(i);
            }
        }

        int ap_count = 0;
        for (int i = 1; i <= N; ++i) {
            if (is_ap[i]) {
                ap_count++;
            }
        }
        cout << ap_count << endl;
    }

    return 0;
}
