/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<pair<string,string>> rels;
    rels.reserve(N);
    vector<string> names;
    names.reserve(2LL*N);

    unordered_map<string,int> id;
    id.reserve(2LL*N*2);

    auto getId = [&](const string& s)->int{
        auto it = id.find(s);
        if (it != id.end()) return it->second;
        int nid = (int)names.size();
        id.emplace(s, nid);
        names.push_back(s);
        return nid;
    };

    vector<pair<int,int>> edges;
    edges.reserve(N);

    for (int i = 0; i < N; i++) {
        string P, F;
        cin >> P >> F;
        int a = getId(P);
        int b = getId(F);
        edges.push_back({a,b});
    }

    int M = (int)names.size();
    vector<vector<int>> children(M);
    vector<int> parent(M, -1);

    for (auto &e : edges) {
        int p = e.first, f = e.second;
        children[p].push_back(f);
        parent[f] = p;
    }

    int root = -1;
    for (int i = 0; i < M; i++) {
        if (parent[i] == -1) {
            root = i;
            break;
        }
    }
    if (root == -1) root = 0;

    vector<int> depth(M, 0);
    vector<int> order;
    order.reserve(M);

    vector<int> stack;
    stack.push_back(root);
    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        order.push_back(u);
        for (int v : children[u]) {
            depth[v] = depth[u] + 1;
            stack.push_back(v);
        }
    }

    int maxLog = 1;
    while ((1 << maxLog) <= max(1, M)) maxLog++;
    vector<vector<int>> up(maxLog, vector<int>(M, -1));
    for (int i = 0; i < M; i++) up[0][i] = parent[i];
    for (int k = 1; k < maxLog; k++) {
        for (int i = 0; i < M; i++) {
            int mid = up[k-1][i];
            up[k][i] = (mid == -1) ? -1 : up[k-1][mid];
        }
    }

    auto lca = [&](int a, int b)->int{
        if (a == -1 || b == -1) return -1;
        if (depth[a] < depth[b]) swap(a,b);
        int diff = depth[a] - depth[b];
        for (int k = 0; k < maxLog; k++) {
            if (diff & (1<<k)) a = up[k][a];
        }
        if (a == b) return a;
        for (int k = maxLog-1; k >= 0; k--) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    };

    pair<string,string> bestPair;
    int bestDist = -1;
    bool bestSet = false;

    auto nameLessPair = [&](const pair<string,string>& p1, const pair<string,string>& p2)->bool{
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second < p2.second;
    };

    vector<int> nodes = order;
    if ((int)nodes.size() < M) {
        vector<char> vis(M,0);
        for(int r : nodes) vis[r]=1;
        for(int i=0;i<M;i++) if(!vis[i]) nodes.push_back(i);
        root = root;
    }

    int S = M;
    vector<int> freqDepth;
    freqDepth.assign(M+1,0);

    auto distAB = [&](int a, int b)->int{
        int c = lca(a,b);
        int d = depth[a] + depth[b] - 2*depth[c];
        return d;
    };

    for (int i = 0; i < M; i++) {
        for (int j = i; j < M; j++) {
            int d = distAB(i,j);
            bool improve = false;
            string s1 = names[i], s2 = names[j];
            if (s1 > s2) swap(s1,s2);
            pair<string,string> cand{s1,s2};
            if (!bestSet || d > bestDist) {
                improve = true;
            } else if (d == bestDist) {
                if (nameLessPair(cand, bestPair)) improve = true;
            }
            if (improve) {
                bestSet = true;
                bestDist = d;
                bestPair = cand;
            }
        }
    }

    cout << bestPair.first << " " << bestPair.second << " " << bestDist << "\n";
    return 0;
}