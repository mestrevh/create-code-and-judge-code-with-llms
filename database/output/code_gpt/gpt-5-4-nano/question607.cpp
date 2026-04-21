/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct LiChaoMin {
    struct Line {
        ll m, b;
        bool empty;
        Line(ll m_=0, ll b_=0, bool e=true): m(m_), b(b_), empty(e) {}
        ll get(ll x) const { return m * x + b; }
    };

    struct Node {
        Line ln;
        Node* l = nullptr;
        Node* r = nullptr;
        Node(Line line): ln(line) {}
    };

    ll Xl, Xr;
    Node* root;

    LiChaoMin(ll xl, ll xr): Xl(xl), Xr(xr) {
        root = nullptr;
    }

    void add_line(ll m, ll b) {
        Line newln(m, b, false);
        if (!root) {
            root = new Node(newln);
            return;
        }
        add_line(root, Xl, Xr, newln);
    }

    void add_line(Node* nd, ll l, ll r, const Line& newln) {
        if (nd->ln.empty) {
            nd->ln = newln;
            nd->ln.empty = false;
            return;
        }
        ll mid = (l + r) >> 1;
        bool left = newln.get(l) < nd->ln.get(l);
        bool mdd = newln.get(mid) < nd->ln.get(mid);

        if (mdd) swap(nd->ln, const_cast<Line&>(newln));

        if (l == r) return;

        if (left != mdd) {
            if (!nd->l) nd->l = new Node(new Line(0,0,true));
            add_line(nd->l, l, mid, newln);
        } else {
            if (!nd->r) nd->r = new Node(new Line(0,0,true));
            add_line(nd->r, mid+1, r, newln);
        }
    }

    ll query(ll x) const {
        if (!root) return (ll)4e18;
        return query(root, Xl, Xr, x);
    }

    ll query(Node* nd, ll l, ll r, ll x) const {
        if (!nd) return (ll)4e18;
        ll res = nd->ln.empty ? (ll)4e18 : nd->ln.get(x);
        if (l == r) return res;
        ll mid = (l + r) >> 1;
        if (x <= mid) return min(res, query(nd->l, l, mid, x));
        else return min(res, query(nd->r, mid+1, r, x));
    }
};

struct SegTreeMin {
    int n;
    vector<ll> seg;
    SegTreeMin(int n_=0): n(n_) {
        seg.assign(4*n+4, (ll)4e18);
    }
    void update(int idx, ll val, int v, int tl, int tr) {
        if (tl == tr) {
            seg[v] = min(seg[v], val);
            return;
        }
        int tm = (tl + tr) >> 1;
        if (idx <= tm) update(idx, val, v<<1, tl, tm);
        else update(idx, val, v<<1|1, tm+1, tr);
        seg[v] = min(seg[v<<1], seg[v<<1|1]);
    }
    void update(int idx, ll val) { update(idx, val, 1, 0, n-1); }

    ll query(int l, int r, int v, int tl, int tr) const {
        if (l > r) return (ll)4e18;
        if (l == tl && r == tr) return seg[v];
        int tm = (tl + tr) >> 1;
        return min(query(l, min(r,tm), v<<1, tl, tm),
                   query(max(l,tm+1), r, v<<1|1, tm+1, tr));
    }
    ll query(int l, int r) const {
        if (l > r) return (ll)4e18;
        l = max(l, 0);
        r = min(r, n-1);
        if (l > r) return (ll)4e18;
        return query(l, r, 1, 0, n-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<int> E(N+1);
    for (int i=1;i<=N;i++) cin >> E[i];

    vector<vector<pair<ll,int>>> stores(N+1);
    for (int i=0;i<M;i++) {
        int L;
        ll S;
        ll C;
        cin >> L >> S >> C;
        stores[L].push_back({S, (int)C});
    }

    vector<ll> allS;
    allS.reserve(M);
    for (int l=1;l<=N;l++) {
        for (auto &p: stores[l]) allS.push_back(p.first);
    }
    sort(allS.begin(), allS.end());
    allS.erase(unique(allS.begin(), allS.end()), allS.end());

    auto getSidx = [&](ll S)->int{
        auto it = lower_bound(allS.begin(), allS.end(), S);
        if (it==allS.end() || *it!=S) return -1;
        return (int)(it - allS.begin());
    };

    int K = (int)allS.size();
    if (K==0) {
        cout << -1 << "\n";
        return 0;
    }

    vector<vector<pair<ll,ll>>> queriesAt(N+1);
    vector<vector<pair<ll,ll>>> addAt(N+1);

    vector<ll> f(N+1, (ll)4e18);
    vector<ll> bestAtSIndex(K, (ll)4e18);

    f[0] = 0;

    vector<vector<int>> storeIdxAt(N+1);
    for (int l=1;l<=N;l++) {
        for (auto &p: stores[l]) {
            ll S = p.first;
            ll C = p.second;
            int idx = getSidx(S);
            storeIdxAt[l].push_back(idx);
        }
    }

    vector<vector<pair<ll,ll>>> storeLines(N+1);
    for (int l=1;l<=N;l++) {
        for (auto &p: stores[l]) {
            ll S = p.first;
            ll C = p.second;
            storeLines[l].push_back({S, C});
        }
    }

    vector<vector<pair<ll,ll>>> eventsForS(K);
    for (int l=1;l<=N;l++) {
        for (auto &it: storeLines[l]) {
            ll S = it.first;
            ll C = it.second;
            int idx = getSidx(S);
            eventsForS[idx].push_back({(ll)l, C});
        }
    }

    const ll INF = (ll)4e18;

    ll xMin = 0;
    ll xMax = (ll)1e9;

    vector<LiChaoMin*> lichaoByStep(N+1, nullptr);

    vector<ll> dp(N+1, INF);
    dp[0] = 0;

    for (int i=1;i<=N;i++) {
        int needSidx = lower_bound(allS.begin(), allS.end(), (ll)E[i]) - allS.begin();
        ll best = INF;

        if (needSidx < K) {
            for (int j=needSidx;j<K;j++) {
                best = min(best, bestAtSIndex[j] + (ll)0);
            }
        }

        dp[i] = INF;
        ll curBest = best;
        if (curBest < INF) {
            if (curBest >= (ll)E[i]) {
                dp[i] = curBest - E[i];
            } else {
                dp[i] = INF;
            }
        }
        for (auto &st: storeLines[i]) {
            ll S = st.first;
            ll C = st.second;
            if (S >= (ll)E[i]) {
                ll cand = dp[i] >= INF ? C : min(dp[i], (C));
            }
        }
    }

    vector<ll> dpMoney(N+1, INF);
    dpMoney[0]=0;

    vector<ll> energyAfterMinMoney(N+1, 0);
    energyAfterMinMoney[0]= (ll)0;

    vector<ll> dpEnergy(N+1, INF);
    dpEnergy[0]=0;

    vector<ll> dpMinCost(N+1, INF);
    dpMinCost[0]=0;

    vector<ll> bestEnergyForCost(N+1, INF);

    for (int i=1;i<=N;i++) {
        ll ansEnergy = INF;
        (void)ansEnergy;
    }

    vector<ll> prevBestCost(K, INF);

    vector<ll> dpCost(N+1, INF);
    vector<ll> dpEnergyMax(N+1, -1);
    dpCost[0]=0;
    dpEnergyMax[0]=0;

    for (int i=1;i<=N;i++) {
        dpCost[i]=INF;
        dpEnergyMax[i]=-1;

        for (auto &p : stores[i]) {
            ll S = p.first;
            ll C = p.second;
            if (S < (ll)E[i]) continue;
            ll prevCost = dpCost[i-1];
            if (prevCost>=INF) continue;
            ll newCost = prevCost + C;
            if (newCost < dpCost[i]) {
                dpCost[i]=newCost;
                dpEnergyMax[i]=S - E[i];
            } else if (newCost == dpCost[i]) {
                dpEnergyMax[i]=max(dpEnergyMax[i], S - E[i]);
            }
        }

        ll carryCost = dpCost[i-1];
        if (carryCost < INF && dpEnergyMax[i-1] >= (ll)E[i]) {
            ll newCost = carryCost;
            ll newEnergy = dpEnergyMax[i-1] - E[i];
            if (newCost < dpCost[i]) {
                dpCost[i]=newCost;
                dpEnergyMax[i]=newEnergy;
            } else if (newCost == dpCost[i]) {
                dpEnergyMax[i]=max(dpEnergyMax[i], newEnergy);
            }
        }
    }

    if (dpCost[N] >= INF) cout << -1 << "\n";
    else cout << dpCost[N] << "\n";
    return 0;
}