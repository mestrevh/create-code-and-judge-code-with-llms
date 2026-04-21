/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int k;
    vector<int> v;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Point> points;
    unordered_map<int,int> idx;
    points.reserve(1<<15);

    int m;
    vector<int> dimMax;
    vector<int> dim;
    string op;
    int countOps = 0;

    int64_t MASK = 0;

    while (true) {
        cin >> op;
        if (!cin) break;
        if (op == "END") break;

        if (op == "ADD") {
            int k;
            cin >> k;
            if (!idx.count(k)) {
                int id = (int)points.size();
                idx[k] = id;
                Point p;
                p.k = k;
                p.v.resize(N);
                for (int j = 0; j < N; j++) cin >> p.v[j];
                points.push_back(std::move(p));
            } else {
                int id = idx[k];
                Point &p = points[id];
                p.k = k;
                for (int j = 0; j < N; j++) cin >> p.v[j];
            }

            for (int j = 0; j < N; j++) {
                long long maxNotLess = -1;
                long long domKey = -1;
                int domExists = 0;
                for (const auto &pt : points) {
                    if (pt.v[j] > points[idx[k]].v[j]) {
                        domExists = 1;
                        if (pt.v[j] > maxNotLess) {
                            maxNotLess = pt.v[j];
                            domKey = pt.k;
                        } else if (pt.v[j] == maxNotLess && pt.k > domKey) {
                            domKey = pt.k;
                        }
                    }
                }
            }

            Point &added = points[idx[k]];
            int res = 0;
            for (int j = 0; j < N; j++) {
                bool wDominatedByAdded = true;
                for (const auto &pt : points) {
                    if (pt.k == added.k) continue;
                    if (added.v[j] < pt.v[j]) {
                        wDominatedByAdded = false;
                        break;
                    }
                    if (added.v[j] == pt.v[j] && added.k < pt.k) {
                        wDominatedByAdded = false;
                        break;
                    }
                }
                if (wDominatedByAdded) res++;
            }
            cout << countOps++ << " " << res << "\n";
        } else if (op == "UPD") {
            int k;
            cin >> k;
            int id = idx[k];
            for (int j = 0; j < N; j++) cin >> points[id].v[j];

            Point &cur = points[id];
            int res = 0;
            for (int j = 0; j < N; j++) {
                bool wDominatedByCur = true;
                for (const auto &pt : points) {
                    if (pt.k == cur.k) continue;
                    if (cur.v[j] < pt.v[j]) {
                        wDominatedByCur = false;
                        break;
                    }
                    if (cur.v[j] == pt.v[j] && cur.k < pt.k) {
                        wDominatedByCur = false;
                        break;
                    }
                }
                if (wDominatedByCur) res++;
            }
            cout << countOps++ << " " << res << "\n";
        } else if (op == "MAX") {
            int j;
            cin >> j;
            int bestK = -1;
            vector<int> bestV;
            for (const auto &pt : points) {
                if (bestK == -1) {
                    bestK = pt.k;
                    bestV = pt.v;
                } else {
                    if (pt.v[j] > bestV[j]) {
                        bestK = pt.k;
                        bestV = pt.v;
                    } else if (pt.v[j] == bestV[j] && pt.k > bestK) {
                        bestK = pt.k;
                        bestV = pt.v;
                    }
                }
            }
            cout << countOps++ << " " << bestK;
            for (int jj = 0; jj < N; jj++) cout << " " << bestV[jj];
            cout << "\n";
        } else {
            break;
        }
    }
    return 0;
}