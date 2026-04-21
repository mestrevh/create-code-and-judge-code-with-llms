/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

struct PersonTree {
    int N;
    vector<string> name;
    i128 X;
    i128 K;

    vector<i128> produced;
    vector<int> done;
    vector<int> need; 

    vector<int> parent;
    
    PersonTree(int n, vector<string> nm) : N(n), name(std::move(nm)) {
        produced.assign(N, 0);
        done.assign(N, 0);
    }

    void buildParents() {
        parent.assign(N, -1);
        for (int i = 0; i < N; i++) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if (l < N) parent[l] = i;
            if (r < N) parent[r] = i;
        }
    }

    i128 ceilDiv(i128 a, i128 b) {
        if (b == 0) return 0;
        if (a <= 0) return 0;
        return (a + b - 1) / b;
    }

    i128 maxPossibleForNode(int u) {
        if (2*u + 1 >= N) return X;
        i128 left = maxPossibleForNode(2*u + 1);
        i128 right = maxPossibleForNode(2*u + 2);
        return left + right;
    }

    i128 minimalTimeToProduceNode(int u) {
        i128 best = maxPossibleForNode(u);
        if (best >= K) {
            i128 low = 0, high = 1;
            while (true) {
                i128 producedAt = producedAtTime(u, high);
                if (producedAt >= K || high > (i128)4e18) break;
                high *= 2;
                if (high > (i128)4e18) break;
            }
            low = 0;
            i128 target = K;
            while (low < high) {
                i128 mid = low + (high - low) / 2;
                if (producedAtTime(u, mid) >= target) high = mid;
                else low = mid + 1;
            }
            return low;
        } else {
            return -1;
        }
    }

    i128 producedAtTime(int u, i128 t) {
        if (t <= 0) return 0;
        if (2*u + 1 >= N) {
            return X * t;
        }
        int l = 2*u + 1;
        int r = 2*u + 2;
        i128 leftNeed = K;
        (void)leftNeed;
        i128 prodL = producedAtTime(l, t);
        i128 needAfterL = K;
        if (prodL >= needAfterL) return prodL + 0;
        i128 prodR = producedAtTime(r, t);
        return prodL + min(prodR, K - prodL);
    }

    void distribute(int u, i128 target) {
        if (done[u]) return;
        done[u] = 1;
        if (target <= 0) return;
        if (2*u + 1 >= N) {
            i128 actual = min(X, target);
            produced[u] = actual;
            return;
        }
        int l = 2*u + 1;
        int r = 2*u + 2;

        i128 needL = target;
        i128 maxL = maxPossibleForNode(l);
        i128 takeL = min(needL, maxL);
        distribute(l, takeL);
        i128 prodL = produced[l];

        i128 rem = target - prodL;
        if (rem <= 0) {
            produced[u] = prodL;
            return;
        }
        i128 maxR = maxPossibleForNode(r);
        i128 takeR = min(rem, maxR);
        distribute(r, takeR);
        produced[u] = prodL + produced[r];
    }

    void dfsReport(int u, vector<int>& order) {
        if (2*u + 1 >= N) {
            order.push_back(u);
            return;
        }
        int l = 2*u + 1;
        int r = 2*u + 2;
        dfsReport(l, order);
        dfsReport(r, order);
        order.push_back(u);
    }

    void run() {
        buildParents();
        distribute(0, K);
        bool ok = produced[0] >= K;

        vector<int> order;
        dfsReport(0, order);
        for (int idx : order) {
            int chefe = parent[idx];
            string chefeNome = (chefe == -1 ? "Nairobi" : name[chefe]);
            cout << "Estou dando " << toString(produced[idx]) << " euros a " << chefeNome << "\n";
        }
        cout << (ok ? "Bom trabalho" : "Precisamos acelerar o processo");
    }

    static string toString(i128 v) {
        if (v == 0) return "0";
        bool neg = v < 0;
        if (neg) v = -v;
        string s;
        while (v > 0) {
            int digit = (int)(v % 10);
            s.push_back(char('0' + digit));
            v /= 10;
        }
        if (neg) s.push_back('-');
        reverse(s.begin(), s.end());
        return s;
    }

    PersonTree& operator=(const PersonTree&) = delete;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<string> names(N);
    for (int i = 0; i < N; i++) cin >> names[i];

    long long Xll, Kll;
    cin >> Xll >> Kll;

    PersonTree pt(N, names);
    pt.X = (i128)Xll;
    pt.K = (i128)Kll;
    pt.run();
    return 0;
}