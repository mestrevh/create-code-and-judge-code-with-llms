/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, rev;
    int cap;
    long long cost;
};

struct MinCostMaxFlow {
    int N;
    vector<vector<Edge>> G;
    vector<long long> dist;
    vector<int> pv_v, pv_e;
    vector<bool> inq;

    MinCostMaxFlow(int n): N(n), G(n), dist(n), pv_v(n), pv_e(n), inq(n) {}

    void addEdge(int s, int t, int cap, long long cost) {
        Edge a{t, (int)G[t].size(), cap, cost};
        Edge b{s, (int)G[s].size(), 0, -cost};
        G[s].push_back(a);
        G[t].push_back(b);
    }

    pair<int,long long> minCostMaxFlow(int s, int t, int maxf) {
        int flow = 0;
        long long cost = 0;
        const long long INF = (1LL<<60);

        while (flow < maxf) {
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            pv_v.assign(N, -1);
            pv_e.assign(N, -1);

            deque<int> q;
            q.push_back(s);
            vector<bool> used(N, false);
            used[s] = true;

            while (!q.empty()) {
                int v = q.front();
                q.pop_front();
                used[v] = false;
                for (int i = 0; i < (int)G[v].size(); i++) {
                    Edge &e = G[v][i];
                    if (e.cap <= 0) continue;
                    long long nd = dist[v] + e.cost;
                    if (nd < dist[e.to]) {
                        dist[e.to] = nd;
                        pv_v[e.to] = v;
                        pv_e[e.to] = i;
                        if (!used[e.to]) {
                            used[e.to] = true;
                            if (!q.empty() && nd < dist[q.front()]) q.push_front(e.to);
                            else q.push_back(e.to);
                        }
                    }
                }
            }

            if (dist[t] == INF) break;

            int addf = maxf - flow;
            int v = t;
            while (v != s) {
                int u = pv_v[v];
                int ei = pv_e[v];
                addf = min(addf, G[u][ei].cap);
                v = u;
            }

            v = t;
            while (v != s) {
                int u = pv_v[v];
                int ei = pv_e[v];
                Edge &e = G[u][ei];
                e.cap -= addf;
                G[v][e.rev].cap += addf;
                v = u;
            }

            flow += addf;
            cost += dist[t] * addf;
        }
        return {flow, cost};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, P, R;
    int B;
    if (!(cin >> D >> P >> R >> B)) return 0;

    vector<int> S(D+1), T(P+1);
    for (int i = 1; i <= D; i++) cin >> S[i];
    for (int j = 1; j <= P; j++) cin >> T[j];

    vector<pair<int,int>> rivals;
    rivals.reserve(R);
    for (int k = 0; k < R; k++) {
        int x, y;
        cin >> x >> y;
        rivals.push_back({x,y});
    }

    long long baseDP = D;
    long long basePR = P;

    int N1 = D + P;
    vector<vector<int>> adj(N1);
    vector<int> col(N1, -1);
    vector<int> compId(N1, -1);
    vector<int> compFlip;
    vector<int> order;
    vector<int> visited(N1, 0);

    for (int i = 0; i < D; i++) {
        int u = i;
        if (visited[u]) continue;
        queue<int> q;
        q.push(u);
        visited[u] = 1;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto [x,y]: rivals) {} 
        }
    }

    vector<vector<int>> g(N1);
    for (auto [x,y]: rivals) {
        int u = x-1;
        int v = D + (y-1);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cid = 0;
    vector<vector<int>> nodesInComp;
    vector<int> compParitySize0, compParitySize1;
    vector<int> compParityCost0, compParityCost1;

    vector<int> compA, compB;
    vector<int> part0Count, part1Count;
    vector<int> part0Cost, part1Cost;
    vector<int> compDcost, compPcost;

    vector<int> color(N1, -1);
    vector<int> inComp0Count, inComp1Count;
    vector<int> inComp0Cost, inComp1Cost;
    vector<int> compTotalR;

    for (int i = 0; i < N1; i++) {
        if (color[i] != -1) continue;
        queue<int> q;
        q.push(i);
        color[i] = 0;

        vector<int> c0, c1;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            if (color[v] == 0) c0.push_back(v);
            else c1.push_back(v);
            for (int to: g[v]) {
                if (color[to] == -1) {
                    color[to] = color[v] ^ 1;
                    q.push(to);
                } else {
                    if (color[to] == color[v]) {
                        cout << "0 0\n";
                        return 0;
                    }
                }
            }
        }
        nodesInComp.push_back({});
        compId[i] = cid;
        cid++;
        part0Count.push_back((int)c0.size());
        part1Count.push_back((int)c1.size());

        long long cost0 = 0, cost1 = 0;
        for (int v: c0) {
            if (v < D) cost1 += S[v+1];
            else cost0 += T[v - D + 1];
        }
        for (int v: c1) {
            if (v < D) cost0 += S[v+1];
            else cost1 += T[v - D + 1];
        }
        part0Cost.push_back((int)cost0);
        part1Cost.push_back((int)cost1);
    }

    int C = cid;

    auto computeMaxForPD = [&](bool wantPD) -> int {
        vector<int> costsA(C), costsB(C), gainA(C), gainB(C);
        for (int i = 0; i < C; i++) {
            int sz0 = part0Count[i];
            int sz1 = part1Count[i];
            int cost0 = part0Cost[i];
            int cost1 = part1Cost[i];

            int gain0 = 0, gain1 = 0;
            for (int v = 0; v < 2; v++) {}
            costsA[i] = cost0;
            costsB[i] = cost1;

            if (wantPD) {
                long long g0 = 0, g1 = 0;
                for (int v = 0; v < N1; v++) {}
            }

            costsA[i] = cost0;
            costsB[i] = cost1;
        }

        vector<int> dp(B+1, -1);
        dp[0] = 0;

        int ans = 0;
        for (int i = 0; i < C; i++) {
            vector<int> ndp(B+1, -1);
            for (int b = 0; b <= B; b++) if (dp[b] >= 0) {
                int nb0 = b + costsA[i];
                if (nb0 <= B) ndp[nb0] = max(ndp[nb0], dp[b] + (wantPD ? part0Count[i] : part1Count[i])); 
                int nb1 = b + costsB[i];
                if (nb1 <= B) ndp[nb1] = max(ndp[nb1], dp[b] + (wantPD ? part1Count[i] : part0Count[i])); 
            }
            dp.swap(ndp);
        }

        for (int b = 0; b <= B; b++) ans = max(ans, dp[b]);
        return ans;
    };

    int maxPD = 0, maxPR = 0;

    {
        vector<int> colorCheck = color;
        vector<vector<int>> comps;
    }

    int totalNodes = D + P;
    vector<int> dpPD(B+1, -1), dpPR(B+1, -1);

    dpPD[0] = 0;
    dpPR[0] = 0;

    vector<int> compGain0_PD(C), compGain1_PD(C);
    vector<int> compGain0_PR(C), compGain1_PR(C);
    vector<int> compCost0(C), compCost1(C);

    for (int i = 0; i < C; i++) {
        compCost0[i] = part0Cost[i];
        compCost1[i] = part1Cost[i];

        int cntPD_when0 = 0;
        int cntPD_when1 = 0;
        int cntPR_when0 = 0;
        int cntPR_when1 = 0;

        compGain0_PD[i] = 0;
        compGain1_PD[i] = 0;
        compGain0_PR[i] = 0;
        compGain1_PR[i] = 0;

        compGain0_PD[i] = 0;
        compGain0_PR[i] = 0;
        compGain1_PD[i] = 0;
        compGain1_PR[i] = 0;
    }

    vector<int> tempColor = color;
    vector<int> cidAssign(N1, -1);
    int cur = 0;
    for (int i = 0; i < N1; i++) if (cidAssign[i] == -1) {
        queue<int> q;
        q.push(i);
        cidAssign[i] = cur;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int to: g[v]) if (cidAssign[to] == -1) { cidAssign[to] = cur; q.push(to); }
        }
        cur++;
    }

    vector<int> gain0PD(C,0), gain1PD(C,0), gain0PR(C,0), gain1PR(C,0);
    vector<int> cost0(C,0), cost1(C,0);

    for (int i = 0; i < N1; i++) {
        int comp = cidAssign[i];
        int c = color[i];
        if (i < D) {
            if (c == 0) {
                cost1[comp] += S[i+1];
                gain0PD[comp] += 0;
                gain1PD[comp] += 1;
                gain0PR[comp] += 0;
                gain1PR[comp] += 0;
            } else {
                cost0[comp] += S[i+1];
                gain0PD[comp] += 1;
                gain1PD[comp] += 0;
                gain0PR[comp] += 0;
                gain1PR[comp] += 0;
            }
        } else {
            int j = i - D + 1;
            if (c == 0) {
                cost0[comp] += T[j];
                gain0PD[comp] += 0;
                gain1PD[comp] += 0;
                gain0PR[comp] += 0;
                gain1PR[comp] += 1;
            } else {
                cost1[comp] += T[j];
                gain0PD[comp] += 0;
                gain1PD[comp] += 0;
                gain0PR[comp] += 1;
                gain1PR[comp] += 0;
            }
        }
    }

    for (int i = 0; i < C; i++) {
        compCost0[i] = cost0[i];
        compCost1[i] = cost1[i];
    }

    for (int i = 0; i < C; i++) {
        vector<int> ndpPD(B+1, -1), ndpPR(B+1, -1);
        for (int b = 0; b <= B; b++) if (dpPD[b] >= 0) {
            int nb0 = b + compCost0[i];
            if (nb0 <= B) ndpPD[nb0] = max(ndpPD[nb0], dpPD[b] + gain0PD[i]);
            int nb1 = b + compCost1[i];
            if (nb1 <= B) ndpPD[nb1] = max(ndpPD[nb1], dpPD[b] + gain1PD[i]);
        }
        dpPD.swap(ndpPD);

        for (int b = 0; b <= B; b++) if (dpPR[b] >= 0) {
            int nb0 = b + compCost0[i];
            if (nb0 <= B) ndpPR[nb0] = max(ndpPR[nb0], dpPR[b] + gain0PR[i]);
            int nb1 = b + compCost1[i];
            if (nb1 <= B) ndpPR[nb1] = max(ndpPR[nb1], dpPR[b] + gain1PR[i]);
        }
        dpPR.swap(ndpPR);
    }

    for (int b = 0; b <= B; b++) {
        if (dpPD[b] > maxPD) maxPD = dpPD[b];
        if (dpPR[b] > maxPR) maxPR = dpPR[b];
    }

    cout << maxPD << " " << maxPR << "\n";
    return 0;
}