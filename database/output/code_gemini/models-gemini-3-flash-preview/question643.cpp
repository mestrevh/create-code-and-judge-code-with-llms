/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct VEdge {
    long long x, y1, y2;
};

struct HEdge {
    long long y, x1, x2;
};

bool isOnBoundary(long long qx, long long qy, const vector<VEdge>& vEdges, const vector<HEdge>& hEdges) {
    for (const auto& e : vEdges) {
        if (qx == e.x && qy >= e.y1 && qy <= e.y2) return true;
    }
    for (const auto& e : hEdges) {
        if (qy == e.y && qx >= e.x1 && qx <= e.x2) return true;
    }
    return false;
}

bool isInside(long long qx, long long qy, const vector<VEdge>& vEdges) {
    int count = 0;
    for (const auto& e : vEdges) {
        if (e.x > qx && qy >= e.y1 && qy < e.y2) {
            count++;
        }
    }
    return count % 2 != 0;
}

bool dfs(int u, const vector<vector<int>>& adj, vector<int>& matchR, vector<bool>& vis) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            if (matchR[v] == -1 || dfs(matchR[v], adj, matchR, vis)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while (cin >> N && N != 0) {
        vector<long long> X(N), Y(N);
        set<long long> setUx, setUy;
        for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
        
        vector<VEdge> vEdges;
        vector<HEdge> hEdges;
        for (int i = 0; i < N; ++i) {
            int j = (i + 1) % N;
            if (X[i] == X[j]) {
                vEdges.push_back({X[i], min(Y[i], Y[j]), max(Y[i], Y[j])});
                setUx.insert(X[i]);
            } else {
                hEdges.push_back({Y[i], min(X[i], X[j]), max(X[i], X[j])});
                setUy.insert(Y[i]);
            }
        }
        
        vector<long long> Ux(setUx.begin(), setUx.end());
        vector<long long> Uy(setUy.begin(), setUy.end());
        int nX = Ux.size(), nY = Uy.size();
        
        vector<vector<int>> adj(nX);
        for (int i = 0; i < nX; ++i) {
            for (int j = 0; j < nY; ++j) {
                if (!isOnBoundary(Ux[i], Uy[j], vEdges, hEdges) && !isInside(Ux[i], Uy[j], vEdges)) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int matching = 0;
        vector<int> matchR(nY, -1);
        for (int i = 0; i < nX; ++i) {
            vector<bool> vis(nY, false);
            if (dfs(i, adj, matchR, vis)) {
                matching++;
            }
        }
        
        cout << nX + nY - matching << "\n";
    }
    return 0;
}