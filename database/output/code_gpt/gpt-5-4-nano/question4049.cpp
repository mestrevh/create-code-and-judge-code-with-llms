/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Establishment {
    string name;
    long long x, y;
    string flavor;
    double price;
};

struct Choice {
    int idx;
    long long dist2;
    double price;
};

static string trim(const string& s) {
    size_t a = 0, b = s.size();
    while (a < b && isspace((unsigned char)s[a])) a++;
    while (b > a && isspace((unsigned char)s[b-1])) b--;
    return s.substr(a, b-a);
}

static bool isFlavorMatch(const string& a, const string& b) {
    return a == b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long gx, gy;
    if (!(cin >> gx >> gy)) return 0;

    int n;
    cin >> n;

    vector<Establishment> est(n);
    for (int i = 0; i < n; i++) {
        cin >> est[i].name;
        cin >> est[i].x >> est[i].y;
        cin >> est[i].flavor;
        cin >> est[i].price;
    }

    int k;
    cin >> k;

    unordered_set<string> want;
    want.reserve(k * 2 + 1);
    for (int i = 0; i < k; i++) {
        string f;
        cin >> f;
        want.insert(f);
    }

    unordered_set<string> eaten;
    eaten.reserve(k * 2 + 1);

    vector<char> visited(n, 0);
    int remaining = n;

    long long cx = gx, cy = gy;

    auto dist2 = [&](long long ax, long long ay) -> long long {
        long long dx = ax - cx;
        long long dy = ay - cy;
        return dx*dx + dy*dy;
    };

    vector<int> order;
    order.reserve(n);

    while (remaining > 0) {
        int bestIdx = -1;
        long long bestDist = 0;
        double bestPrice = 0.0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            long long d = (est[i].x - cx) * (est[i].x - cx) + (est[i].y - cy) * (est[i].y - cy);
            double p = est[i].price;
            if (bestIdx == -1 || d < bestDist || (d == bestDist && p < bestPrice)) {
                bestIdx = i;
                bestDist = d;
                bestPrice = p;
            }
        }

        visited[bestIdx] = 1;
        remaining--;
        order.push_back(bestIdx);

        cx = est[bestIdx].x;
        cy = est[bestIdx].y;

        if (want.find(est[bestIdx].flavor) != want.end()) {
            eaten.insert(est[bestIdx].flavor);
        }
    }

    for (int idx : order) {
        cout << est[idx].name << "\n";
    }

    bool complete = (int)eaten.size() == (int)want.size();
    if (complete && (int)want.size() > 0) {
        cout << "Completou a lista\n";
    } else if (want.size() == 0) {
        cout << "Completou a lista\n";
    } else {
        cout << "Vou fazer as que faltaram quando chegar em casa\n";
    }

    return 0;
}