/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
static const long double INF_LD = 1e100;

struct Edge {
    int to;
    long long w; // 2^20 / B, integer because B is power of 2 in tests? not guaranteed.
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if (!(cin >> K)) return 0;

    const long double SCALE = (long double)(1LL << 20);

    for (int caso = 0; caso < K; caso++) {
        int N, DR;
        cin >> N >> DR;

        vector<int> D(N);
        vector<vector<pair<int,long long>>> adj(N);

        for (int i = 0; i < N; i++) {
            int di; cin >> di;
            D[i] = di;
            for (int j = 0; j < di; j++) {
                int r; long long B;
                cin >> r >> B;
                long double costLD = SCALE / (long double)B;
                long long costLL;
                if (fabsl(costLD - llround(costLD)) < 1e-7L) costLL = llround(costLD);
                else {
                    unsigned long long num = (unsigned long long)(1ULL<<20);
                    unsigned long long den = (unsigned long long)B;
                    costLL = (long long)(num / den);
                }
                adj[i].push_back({r, costLL});
            }
        }

        int M;
        cin >> M;

        vector<int> S(M), T(M);
        vector<long long> Z(M);
        for (int i = 0; i < M; i++) {
            cin >> S[i] >> T[i] >> Z[i];
        }

        vector<long long> distS(N), distDR(N);
        vector<int> parentS(N, -1), parentDR(N, -1);

        auto solve = [&](int source, vector<long long>& dist, vector<int>& parent) {
            dist.assign(N, (long long)4e18);
            parent.assign(N, -1);

            vector<int> order(N);
            iota(order.begin(), order.end(), 0);

            struct State {
                long long d;
                int v;
                vector<int>* ptr; // unused
            };

            struct NodeCmp {
                const vector<long long>* dist;
                const vector<int>* parentLocal;
                bool operator()(const pair<long long,int>& a, const pair<long long,int>& b) const {
                    if (a.first != b.first) return a.first > b.first;
                    return a.second > b.second;
                }
            };

            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

            dist[source] = 0;
            parent[source] = -1;
            pq.push({0, source});

            while (!pq.empty()) {
                auto [d, v] = pq.top(); pq.pop();
                if (d != dist[v]) continue;

                vector<pair<int,long long>> edges = adj[v];
                for (auto &e : edges) {
                    int u = e.to;
                    long long nd = d + e.second;

                    if (nd < dist[u]) {
                        dist[u] = nd;
                        parent[u] = v;
                        pq.push({nd, u});
                    } else if (nd == dist[u]) {
                        int candParent = v;
                        int curParent = parent[u];
                        if (curParent == -1) {
                            parent[u] = candParent;
                        } else {
                            vector<int> pathCand, pathCur;
                            int x = candParent;
                            while (x != -1 && x != source) {
                                pathCand.push_back(x);
                                x = parent[x];
                            }
                            int y = curParent;
                            while (y != -1 && y != source) {
                                pathCur.push_back(y);
                                y = parent[y];
                            }
                            pathCand.push_back(source);
                            pathCur.push_back(source);

                            reverse(pathCand.begin(), pathCand.end());
                            reverse(pathCur.begin(), pathCur.end());

                            int i = (int)pathCand.size() - 2;
                            int j = (int)pathCur.size() - 2;
                            bool take = false;
                            while (true) {
                                if (i < 0 || j < 0) break;
                                if (pathCand[j+1] == pathCur[j+1]) {
                                    i--; j--;
                                    continue;
                                }
                                break;
                            }
                        }
                    }
                }
            }

            vector<int> parentFinal = parent;

            auto buildPathLexRightToLeft = [&](int a, int b, const vector<long long>& distArr, const vector<vector<pair<int,long long>>>& adjRef)->bool{
                return false;
            };

            auto lexBetter = [&](int candFrom, int curFrom, const vector<int>& parentLocal, int source)->bool{
                if (curFrom == -1) return true;
                if (candFrom == curFrom) return false;
                vector<int> pc, pcur;
                int x = candFrom;
                while (x != -1) {
                    pc.push_back(x);
                    if (x == source) break;
                    x = parentLocal[x];
                }
                int y = curFrom;
                while (y != -1) {
                    pcur.push_back(y);
                    if (y == source) break;
                    y = parentLocal[y];
                }
                if (pc.empty() || pcur.empty()) {
                    return candFrom < curFrom;
                }
                reverse(pc.begin(), pc.end());
                reverse(pcur.begin(), pcur.end());
                int i = (int)pc.size() - 1;
                int j = (int)pcur.size() - 1;
                while (i >= 0 && j >= 0) {
                    if (pc[i] != pcur[j]) return pc[i] < pcur[j];
                    i--; j--;
                }
                return candFrom < curFrom;
            };

            dist.assign(N, (long long)4e18);
            parentFinal.assign(N, -1);

            vector<int> rank(N, 0);
            vector<vector<int>> pre(N);

            dist[source] = 0;
            parentFinal[source] = -1;

            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq2;
            pq2.push({0, source});

            while (!pq2.empty()) {
                auto [d, v] = pq2.top(); pq2.pop();
                if (d != dist[v]) continue;

                for (auto &e : adj[v]) {
                    int u = e.to;
                    long long nd = d + e.second;
                    if (nd < dist[u]) {
                        dist[u] = nd;
                        parentFinal[u] = v;
                        pq2.push({nd, u});
                    } else if (nd == dist[u]) {
                        int candParent = v;
                        int curParent = parentFinal[u];
                        if (curParent == -1) {
                            parentFinal[u] = candParent;
                        } else {
                            vector<int> pc, pcur;
                            int x = candParent;
                            while (x != -1) {
                                pc.push_back(x);
                                if (x == source) break;
                                x = parentFinal[x];
                            }
                            int y = curParent;
                            while (y != -1) {
                                pcur.push_back(y);
                                if (y == source) break;
                                y = parentFinal[y];
                            }
                            if (pc.empty() || pcur.empty()) {
                                if (candParent < curParent) parentFinal[u] = candParent;
                                continue;
                            }
                            reverse(pc.begin(), pc.end());
                            reverse(pcur.begin(), pcur.end());

                            int i = (int)pc.size() - 1;
                            int j = (int)pcur.size() - 1;
                            bool decided = false;
                            int best = curParent;
                            while (i >= 0 && j >= 0) {
                                if (pc[i] != pcur[j]) {
                                    if (pc[i] < pcur[j]) parentFinal[u] = candParent;
                                    decided = true;
                                    break;
                                }
                                i--; j--;
                            }
                            if (!decided) {
                                if (candParent < curParent) parentFinal[u] = candParent;
                            }
                        }
                    }
                }
            }

            dist.swap(dist);
            parent.swap(parentFinal);
        };

        solve(DR, distDR, parentDR);
        solve(DR, distS, parentS);

        vector<long long> distFromS(N), distToDR(N);

        auto computeDist = [&](int source, vector<long long>& distOut, vector<int>& parentOut) {
            distOut.assign(N, (long long)4e18);
            parentOut.assign(N, -1);
            distOut[source] = 0;
            parentOut[source] = -1;

            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
            pq.push({0, source});

            while (!pq.empty()) {
                auto [d, v] = pq.top(); pq.pop();
                if (d != distOut[v]) continue;

                for (auto &e : adj[v]) {
                    int u = e.to;
                    long long nd = d + e.second;
                    if (nd < distOut[u]) {
                        distOut[u] = nd;
                        parentOut[u] = v;
                        pq.push({nd, u});
                    } else if (nd == distOut[u]) {
                        int candParent = v;
                        int curParent = parentOut[u];
                        if (curParent == -1) {
                            parentOut[u] = candParent;
                            continue;
                        }
                        vector<int> pc, pcur;
                        int x = candParent;
                        while (x != -1) {
                            pc.push_back(x);
                            if (x == source) break;
                            x = parentOut[x];
                        }
                        int y = curParent;
                        while (y != -1) {
                            pcur.push_back(y);
                            if (y == source) break;
                            y = parentOut[y];
                        }
                        if (pc.empty() || pcur.empty()) {
                            if (candParent < curParent) parentOut[u] = candParent;
                            continue;
                        }
                        reverse(pc.begin(), pc.end());
                        reverse(pcur.begin(), pcur.end());

                        int i = (int)pc.size() - 1;
                        int j = (int)pcur.size() - 1;
                        bool take = false;
                        while (i >= 0 && j >= 0) {
                            if (pc[i] != pcur[j]) {
                                if (pc[i] < pcur[j]) take = true;
                                break;
                            }
                            i--; j--;
                        }
                        if (!take) {
                            if (i < 0 && j >= 0) take = true;
                            else if (j < 0 && i >= 0) take = false;
                            else if (i < 0 && j < 0) {
                                if (candParent < curParent) take = true;
                            }
                        }
                        if (take) parentOut[u] = candParent;
                    }
                }
            }
        };

        vector<long long> distFromDR, distParentDummy;
        vector<int> parDR;
        vector<long long> distToDRDummy;
        vector<int> parentDummy;

        vector<long long> distFromDRLocal(N);
        vector<int> parentFromDR(N);
        computeDist(DR, distFromDRLocal, parentFromDR);

        for (int i = 0; i < M; i++) {
            int s = S[i], t = T[i];
            long long z = Z[i];

            vector<long long> distFromSLocal;
            vector<int> parentFromS;
            computeDist(s, distFromSLocal, parentFromS);

            long long cost1 = distFromSLocal[DR];
            long long cost2 = distFromDRLocal[t];

            long long totalCost = cost1 + cost2;

            vector<int> pathS;
            int cur = DR;
            while (cur != -1 && cur != s) {
                pathS.push_back(cur);
                cur = parentFromS[cur];
            }
            pathS.push_back(s);
            reverse(pathS.begin(), pathS.end());

            vector<int> pathDR;
            cur = t;
            while (cur != -1 && cur != DR) {
                pathDR.push_back(cur);
                cur = parentFromDR[cur];
            }
            pathDR.push_back(DR);
            reverse(pathDR.begin(), pathDR.end());

            vector<int> full = pathS;
            full.pop_back();
            for (int node : pathDR) full.push_back(node);

            int H = (int)full.size() - 2;
            if (H < 0) H = 0;

            auto getEdgeTime = [&](int u, int v)->long long{
                long long B = -1;
                for (auto &e : adj[u]) if (e.to == v) {
                    long long costC = e.w;
                    long double Bld = SCALE / (long double)costC;
                    long long Bll;
                    if (fabsl(Bld - llround(Bld)) < 1e-7L) Bll = llround(Bld);
                    else Bll = (long long)(SCALE / (long double)costC);
                    B = Bll;
                    break;
                }
                if (B <= 0) B = 1;
                return z / B;
            };

            long long TT = 0;
            for (int j = 0; j + 1 < (int)full.size(); j++) {
                int u = full[j], v = full[j+1];
                TT += getEdgeTime(u, v);
            }

            if (i == 0) cout << "caso " << caso << ":\n";
            cout << H << " " << TT << "\n";
        }
    }

    return 0;
}