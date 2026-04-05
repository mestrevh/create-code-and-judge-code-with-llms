/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool canFinishWithX(int X, const vector<int>& obs) {
    int N = (int)obs.size();
    int maxM = obs.back();
    int reach = 0;
    for (int i = 0; i < N; i++) {
        if (obs[i] == 1) return false;
        while (reach + 1 < obs[i]) {
            reach = obs[i] - 1;
        }
        if (X == 0) return false;
        if (reach < obs[i] - 1) return false;
        int next = reach + 1;
        if (next == obs[i]) return false;
        reach = next;
        if (i + 1 < N && obs[i + 1] - obs[i] <= X) {
            int j = i;
            while (j < N && obs[j] <= reach + X) {
                if (obs[j] == reach) return false;
                j++;
            }
            i = j - 1;
        }
    }
    (void)maxM;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> obs(N);
    for (int i = 0; i < N; i++) cin >> obs[i];

    int maxPos = obs.back();
    vector<int> isObs(maxPos + 1, 0);
    for (int p : obs) if (0 <= p && p <= maxPos) isObs[p] = 1;

    int lo = 0, hi = maxPos + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        int X = mid;
        vector<char> dp(maxPos + X + 2, 0);
        dp[0] = 1;
        for (int i = 0; i <= maxPos + 1; i++) {
            if (!dp[i]) continue;
            if (i + 1 < (int)dp.size()) {
                if (i + 1 >= 0 && i + 1 <= maxPos && isObs[i + 1] == 1) {
                } else if (i + 1 <= maxPos + 1) dp[i + 1] = 1;
            }
            if (i + X < (int)dp.size()) {
                int j = i + X;
                if (j <= maxPos && isObs[j] == 1) {
                } else if (j <= maxPos + 1) dp[j] = 1;
            }
        }
        bool ok = false;
        for (int i = maxPos + 1; i >= maxPos; i--) {
            if (i < (int)dp.size() && dp[i]) { ok = true; break; }
        }
        if (ok) hi = mid;
        else lo = mid;
    }

    int X = hi;
    vector<char> dp(maxPos + X + 2, 0);
    vector<int> parent(maxPos + X + 2, -1);
    vector<char> how(maxPos + X + 2, 0);
    dp[0] = 1;
    for (int i = 0; i <= maxPos + 1; i++) {
        if (!dp[i]) continue;
        if (i + 1 <= maxPos + 1) {
            if (i + 1 <= maxPos && isObs[i + 1]) {
            } else if (!dp[i + 1]) {
                dp[i + 1] = 1;
                parent[i + 1] = i;
                how[i + 1] = 1;
            }
        }
        int j = i + X;
        if (j <= maxPos + 1) {
            if (j <= maxPos && isObs[j]) {
            } else if (!dp[j]) {
                dp[j] = 1;
                parent[j] = i;
                how[j] = 0;
            }
        }
    }

    int target = -1;
    for (int i = maxPos + 1; i >= 0; i--) {
        if (i <= maxPos + 1 && dp[i]) { target = i; break; }
    }
    if (target == -1) target = maxPos + 1;

    vector<char> path(maxPos + 1, '0');
    int cur = target;
    while (cur > 0) {
        int prev = parent[cur];
        if (prev < 0) break;
        if (prev + 1 == cur) {
            if (cur <= maxPos) path[cur] = '1';
        } else {
            int start = prev;
            for (int t = prev + 1; t <= min(maxPos, cur); t++) {
                if (t != cur && isObs[t]) {}
            }
            if (cur <= maxPos) path[cur] = '1';
        }
        cur = prev;
    }

    for (int i = 0; i <= maxPos; i++) cout << (isObs[i] ? '1' : '0');
    cout << "\n";
    cout << "Pulo minimo: " << X << "\n";
    return 0;
}