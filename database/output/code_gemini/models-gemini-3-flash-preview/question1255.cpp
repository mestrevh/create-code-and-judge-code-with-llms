/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

struct State {
    int u;
    int t;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E, S, M;
    if (!(cin >> N >> E >> S >> M)) return 0;

    vector<int> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];

    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < N && v >= 0 && v < N) {
            adj[u].push_back(v);
        }
    }

    ll max_L = 10000000 / N;
    if (max_L < 1) max_L = 1;
    ll L = 1;
    for (int i = 0; i < N; ++i) {
        if (P[i] > 1) {
            ll g = gcd(L, (ll)P[i]);
            ll next_term = (ll)P[i] / g;
            if (max_L / next_term < L) {
                L = max_L;
                break;
            }
            L *= next_term;
        }
    }
    if (L <= 0) L = 1;

    vector<bool> visited((size_t)N * (L + 1), false);
    queue<State> q;

    q.push({E, 0});
    visited[(size_t)E * L + 0] = true;

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.u == S) {
            cout << curr.t << " minutos" << endl;
            return 0;
        }

        for (int v : adj[curr.u]) {
            int nt = curr.t + 1;
            // Rule: monster in v attacks if nt > 0 and nt % P[v] == 0
            if (P[v] <= 0 || nt % P[v] != 0) {
                size_t idx = (size_t)v * L + (nt % L);
                if (!visited[idx]) {
                    visited[idx] = true;
                    q.push({v, nt});
                }
            }
        }
        
        // Safety break to prevent infinite loops if something is wrong
        if (curr.t > 2000000) break;
    }

    cout << "Araragi morreu" << endl;

    return 0;
}

