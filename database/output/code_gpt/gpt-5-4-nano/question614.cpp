/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P, V;
    if (!(cin >> P >> V)) return 0;

    vector<pair<ll,ll>> plants(P+1);
    for (int i = 1; i <= P; i++) {
        ll x, y;
        cin >> x >> y;
        plants[i] = {x, y};
    }

    vector<pair<ll,ll>> poly(V);
    for (int i = 0; i < V; i++) {
        ll x, y;
        cin >> x >> y;
        poly[i] = {x, y};
    }

    vector<ll> xs;
    xs.reserve(2 * V + P);
    for (auto &pt: poly) xs.push_back(pt.first);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    auto inside = [&](ll x, ll y)->bool{
        int ix = int(lower_bound(xs.begin(), xs.end(), x) - xs.begin());
        if (ix == (int)xs.size()) return false;

        int start = ix;
        int end = ix;
        if (start < 0 || start >= (int)xs.size()) return false;

        ll eps = 0;
        int leftCount = 0;
        int rightCount = 0;

        ll x0 = x;

        int idx0 = int(lower_bound(xs.begin(), xs.end(), x0) - xs.begin());
        if (idx0 < (int)xs.size() && xs[idx0] == x0) {
            return false;
        }
        if (idx0 == 0 || idx0 == (int)xs.size()) return false;
        ll xL = xs[idx0-1];
        ll xR = xs[idx0];

        struct Seg { ll y1,y2; };
        vector<Seg> horizontals;
        horizontals.reserve(V);

        for (int i = 0; i < V; i++) {
            auto [x1,y1] = poly[i];
            auto [x2,y2] = poly[(i+1)%V];
            if (y1 == y2) {
                ll yl = y1;
                ll xl = min(x1,x2);
                ll xr = max(x1,x2);
                horizontals.push_back({yl, yl});
                (void)xl;
                (void)xr;
            }
        }

        vector<pair<ll,ll>> horSegs; // not used
        (void)horSegs;

        int crossings = 0;

        for (int i = 0; i < V; i++) {
            ll x1 = poly[i].first, y1 = poly[i].second;
            ll x2 = poly[(i+1)%V].first, y2 = poly[(i+1)%V].second;

            if (y1 == y2) continue;
            if ((y1 <= y && y < y2) || (y2 <= y && y < y1)) {
                ll xint;
                if (x1 == x2) {
                    xint = x1;
                } else {
                    long double t = (long double)(y - y1) / (long double)(y2 - y1);
                    xint = (ll)floor((long double)x1 + (long double)(x2 - x1)*t);
                }
                if (xint > x0) crossings++;
            }
        }
        return (crossings % 2 == 1);
    };

    ll sumOut = 0;
    ll total = 1LL * P * (P + 1) / 2;
    ll insideSum = 0;

    for (int i = 1; i <= P; i++) {
        ll x = plants[i].first, y = plants[i].second;
        if (inside(x, y)) insideSum += i;
        else sumOut += i;
    }

    cout << sumOut << "\n";
    return 0;
}