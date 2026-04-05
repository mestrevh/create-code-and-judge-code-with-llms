/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

struct SplitResult {
    vector<int64> left;
    vector<int64> right;
};

static inline int64 floorAverage(const vector<int64>& a) {
    i128 sum = 0;
    for (auto x : a) sum += (i128)x;
    i128 n = (i128)a.size();
    i128 q = sum / n;
    if (sum < 0 && sum % n != 0) q -= 1;
    return (int64)q;
}

static inline int64 genPivotValue(const vector<int64>& a) {
    int64 avg = floorAverage(a);
    int64 bestVal = 0;
    bool has = false;
    int64 bestDist = 0;
    for (auto x : a) {
        int64 dist = llabs(x - avg);
        if (!has || dist < bestDist || (dist == bestDist && x < bestVal)) {
            has = true;
            bestDist = dist;
            bestVal = x;
        }
    }
    return bestVal;
}

static inline SplitResult partitionLeftEq(const vector<int64>& a, int64 pivotVal) {
    SplitResult res;
    res.left.reserve(a.size());
    res.right.reserve(a.size());
    for (auto x : a) {
        if (x <= pivotVal) res.left.push_back(x);
        else res.right.push_back(x);
    }
    return res;
}

static vector<int64> genArray(int n, int64 x0, int64 a, int64 c, int64 m) {
    vector<int64> x(n);
    x[0] = x0;
    for (int i = 1; i < n; i++) {
        i128 v = (i128)a * (i128)x[i-1] + (i128)c;
        v %= (i128)m;
        x[i] = (int64)v;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while ( (cin >> n) ) {
        int64 x0, a, c, m;
        if (!(cin >> x0 >> a >> c >> m)) break;

        vector<int64> arr = genArray(n, x0, a, c, m);
        vector<int64> sorted = arr;
        sort(sorted.begin(), sorted.end());
        unordered_map<int64, vector<int>> pos;
        pos.reserve(n * 2 + 1);
        for (int i = 0; i < n; i++) pos[sorted[i]].push_back(i + 1);

        for (auto &kv : pos) {
            auto &v = kv.second;
            sort(v.begin(), v.end());
        }

        unordered_map<int64, int> usedCnt;
        usedCnt.reserve(pos.size() * 2 + 1);

        vector<vector<int64>> stackLeft;
        vector<pair<int,int>> dummy;
        (void)stackLeft;
        vector<vector<int64>> leftParts;
        vector<vector<int64>> rightParts;
        (void)leftParts; (void)rightParts;

        vector<vector<int64>> segments;
        segments.push_back(arr);

        vector<pair<int64,int>> pivotsOut;
        pivotsOut.reserve(1024);

        size_t segIdx = 0;
        while (segIdx < segments.size()) {
            vector<int64> current = std::move(segments[segIdx]);
            segIdx++;

            if (current.empty()) continue;
            int64 pivotVal = genPivotValue(current);

            SplitResult sp = partitionLeftEq(current, pivotVal);
            vector<int64> left = std::move(sp.left);
            vector<int64> right = std::move(sp.right);

            auto it = pos.find(pivotVal);
            int place = -1;
            if (it != pos.end()) {
                int &uc = usedCnt[pivotVal];
                place = it->second[uc];
                uc++;
            }
            pivotsOut.push_back({pivotVal, place});

            if (!left.empty()) segments.push_back(std::move(left));
            if (!right.empty()) segments.push_back(std::move(right));
        }

        for (size_t i = 0; i < pivotsOut.size(); i++) {
            if (i) cout << "";
            cout << "(" << pivotsOut[i].first << "," << pivotsOut[i].second << ")";
        }
        if (!cin.eof()) cout << "\n";
    }
    return 0;
}