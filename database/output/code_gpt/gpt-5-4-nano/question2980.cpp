/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> hE(n), pE(n), hX(n), pX(n);
    vector<vector<int>> atE(n), atX(n);

    for (int i = 0; i < n; i++) {
        int h, p, k;
        cin >> h >> p >> k;
        hE[i] = h;
        pE[i] = p;
        atE[i].resize(k);
        for (int j = 0; j < k; j++) cin >> atE[i][j];
    }
    for (int i = 0; i < n; i++) {
        int h, p, k;
        cin >> h >> p >> k;
        hX[i] = h;
        pX[i] = p;
        atX[i].resize(k);
        for (int j = 0; j < k; j++) cin >> atX[i][j];
    }

    auto solve = [&](const vector<int>& hA, const vector<int>& pA, const vector<vector<int>>& atA,
                      const vector<int>& hB, const vector<int>& pB, const vector<vector<int>>& atB) -> pair<string,int> {
        int nA = (int)hA.size(), nB = (int)hB.size();
        long long totalHealthB = 0;
        for (int i = 0; i < nB; i++) totalHealthB += hB[i];

        vector<vector<int>> targetsBfromA(nA);
        for (int i = 0; i < nA; i++) {
            targetsBfromA[i].assign(atA[i].begin(), atA[i].end());
        }

        vector<vector<int>> targetsAfromB(nB);
        for (int i = 0; i < nB; i++) targetsAfromB[i].assign(atB[i].begin(), atB[i].end());

        vector<long long> capB(nB, 0), capA(nA, 0);
        vector<char> reachableB(nB, 0), reachableA(nA, 0);

        auto computeCaps = [&](const vector<int>& hAttacker, const vector<int>& pAttacker, const vector<vector<int>>& atAttacker,
                                vector<long long>& capDef, vector<char>& reachableDef,
                                const vector<int>& hDef, const vector<vector<int>>& atDefFromDef) {
            int Ndef = (int)hDef.size();
            int Natt = (int)hAttacker.size();
            vector<int> indeg(Ndef, 0);
            for (int u = 0; u < Natt; u++) {
                for (int v : atAttacker[u]) indeg[v]++;
            }

            vector<vector<int>> adj(Natt);
            for (int u = 0; u < Natt; u++) adj[u] = atAttacker[u];

            queue<int> q;
            for (int v = 0; v < Ndef; v++) {
                reachableDef[v] = (indeg[v] > 0) ? 1 : 0;
            }

            for (int v = 0; v < Ndef; v++) capDef[v] = 0;

            vector<int> attackedBy(Ndef, 0);
            for (int u = 0; u < Natt; u++) {
                for (int v : atAttacker[u]) attackedBy[v] = 1;
            }
            for (int v = 0; v < Ndef; v++) {
                if (!attackedBy[v]) {
                    capDef[v] = 0;
                }
            }

            for (int v = 0; v < Ndef; v++) {
                if (!attackedBy[v]) continue;
                long long best = 0;
                for (int u = 0; u < Natt; u++) {
                    for (int vv : atAttacker[u]) if (vv == v) best = max(best, (long long)pAttacker[u]);
                }
                capDef[v] = best;
            }
        };

        computeCaps(hA, pA, atA, capB, reachableB, hB, atB);
        computeCaps(hB, pB, atB, capA, reachableA, hA, atA);

        auto ceilDiv = [&](long long a, long long b) -> long long {
            if (b == 0) return (a > 0) ? (long long)4e18 : 0;
            return (a + b - 1) / b;
        };

        const long long INF = (long long)4e18;

        vector<long long> minTurnsToKillB(nB, INF);
        for (int i = 0; i < nB; i++) {
            if (capB[i] == 0) {
                minTurnsToKillB[i] = INF;
            } else {
                minTurnsToKillB[i] = ceilDiv(hB[i], capB[i]);
            }
        }
        vector<long long> minTurnsToKillA(nA, INF);
        for (int i = 0; i < nA; i++) {
            if (capA[i] == 0) minTurnsToKillA[i] = INF;
            else minTurnsToKillA[i] = ceilDiv(hA[i], capA[i]);
        }

        long long bestEntityWin = INF;
        for (int i = 0; i < nB; i++) {
            bestEntityWin = min(bestEntityWin, minTurnsToKillB[i]);
        }
        long long bestXWin = INF;
        for (int i = 0; i < nA; i++) {
            bestXWin = min(bestXWin, minTurnsToKillA[i]);
        }

        if (bestEntityWin <= bestXWin) {
            return { "Entity", (int)bestEntityWin };
        } else {
            return { "X", (int)bestXWin };
        }
    };

    auto resEntityFirst = [&]() -> pair<string,int> {
        int nE_ = n, nX_ = n;
        vector<long long> capX(nX_, 0), capE(nE_, 0);

        for (int j = 0; j < nX_; j++) {
            long long best = 0;
            for (int i = 0; i < nE_; i++) {
                for (int v : atE[i]) if (v == j) best = max(best, (long long)pE[i]);
            }
            capX[j] = best;
        }
        for (int i = 0; i < nE_; i++) {
            long long best = 0;
            for (int j = 0; j < nX_; j++) {
                for (int v : atX[j]) if (v == i) best = max(best, (long long)pX[j]);
            }
            capE[i] = best;
        }

        auto ceilDiv = [&](long long a, long long b) -> long long {
            if (b == 0) return (a > 0) ? (long long)4e18 : 0;
            return (a + b - 1) / b;
        };

        const long long INF = (long long)4e18;
        long long tEntityWin = INF;
        for (int j = 0; j < nX_; j++) {
            if (capX[j] == 0) continue;
            tEntityWin = min(tEntityWin, ceilDiv(hX[j], capX[j]));
        }
        if (tEntityWin == INF) tEntityWin = INF;

        long long tXWin = INF;
        for (int i = 0; i < nE_; i++) {
            if (capE[i] == 0) continue;
            tXWin = min(tXWin, ceilDiv(hE[i], capE[i]));
        }

        if (tEntityWin <= tXWin) {
            return { "Entity", (int)tEntityWin };
        } else {
            return { "X", (int)tXWin };
        }
    };

    auto ans = resEntityFirst();
    cout << ans.first << " wins in " << ans.second << " turns\n";
    return 0;
}