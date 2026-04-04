/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> szPD;
    vector<int> szPRISM;
    vector<int> totalCost;

    DSU(int d, int p) {
        parent.resize(d + p);
        iota(parent.begin(), parent.end(), 0);
        szPD.assign(d + p, 0);
        szPRISM.assign(d + p, 0);
        totalCost.assign(d + p, 0);
        for (int i = 0; i < d; ++i) szPD[i] = 1;
        for (int i = d; i < d + p; ++i) szPRISM[i] = 1;
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            szPD[root_j] += szPD[root_i];
            szPRISM[root_j] += szPRISM[root_i];
            totalCost[root_j] += totalCost[root_i];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D, P, R, B;
    if (!(cin >> D >> P >> R >> B)) return 0;

    DSU dsu(D, P);

    for (int i = 0; i < D; ++i) {
        int s;
        cin >> s;
        dsu.totalCost[i] = s;
    }

    for (int i = 0; i < P; ++i) {
        int t;
        cin >> t;
        dsu.totalCost[D + i] = t;
    }

    for (int i = 0; i < R; ++i) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u - 1, D + v - 1);
    }

    struct Component {
        int cost;
        int gainPD;
        int gainPRISM;
    };

    vector<Component> comps;
    for (int i = 0; i < D + P; ++i) {
        if (dsu.parent[i] == i) {
            int gPD = dsu.szPRISM[i] - dsu.szPD[i];
            int gPRISM = dsu.szPD[i] - dsu.szPRISM[i];
            comps.push_back({dsu.totalCost[i], gPD, gPRISM});
        }
    }

    vector<int> dpPD(B + 1, 0);
    for (auto& c : comps) {
        if (c.gainPD > 0) {
            for (int b = B; b >= c.cost; --b) {
                dpPD[b] = max(dpPD[b], dpPD[b - c.cost] + c.gainPD);
            }
        }
    }

    vector<int> dpPRISM(B + 1, 0);
    for (auto& c : comps) {
        if (c.gainPRISM > 0) {
            for (int b = B; b >= c.cost; --b) {
                dpPRISM[b] = max(dpPRISM[b], dpPRISM[b - c.cost] + c.gainPRISM);
            }
        }
    }

    cout << D + dpPD[B] << " " << P + dpPRISM[B] << endl;

    return 0;
}