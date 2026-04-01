/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 50005;
int p[MAXN], M[MAXN], status[MAXN];
int n, q;

struct Node {
    int l, r, cnt;
} tree[MAXN * 60];

int root[MAXN], nodes_cnt = 0;

int update(int prev, int l, int r, int val) {
    int curr = ++nodes_cnt;
    tree[curr] = tree[prev];
    tree[curr].cnt++;
    if (l == r) return curr;
    int mid = l + (r - l) / 2;
    if (val <= mid) tree[curr].l = update(tree[prev].l, l, mid, val);
    else tree[curr].r = update(tree[prev].r, mid + 1, r, val);
    return curr;
}

int query(int nodeL, int nodeR, int l, int r, int qr) {
    if (qr < l) return 0;
    if (r <= qr) return tree[nodeR].cnt - tree[nodeL].cnt;
    int mid = l + (r - l) / 2;
    int res = query(tree[nodeL].l, tree[nodeR].l, l, mid, qr);
    if (qr > mid) res += query(tree[nodeL].r, tree[nodeR].r, mid + 1, r, qr);
    return res;
}

int find_kth(int nodeL, int nodeR, int l, int r, int k) {
    if (l == r) return l;
    int mid = l + (r - l) / 2;
    int cnt_left = tree[tree[nodeR].l].cnt - tree[tree[nodeL].l].cnt;
    if (k <= cnt_left) return find_kth(tree[nodeL].l, tree[nodeR].l, l, mid, k);
    else return find_kth(tree[nodeL].r, tree[nodeR].r, mid + 1, r, k - cnt_left);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> q)) return 0;
    for (int i = 1; i <= n; i++) cin >> p[i];

    for (int i = 1; i <= n; i++) {
        if (M[i] != 0) continue;
        int curr = i;
        vector<int> path;
        while (M[curr] == 0 && status[curr] == 0) {
            status[curr] = i;
            path.push_back(curr);
            curr = p[curr];
        }
        if (M[curr] == 0 && status[curr] == i) {
            int cycle_start = curr;
            int cycle_min = cycle_start;
            int temp = p[cycle_start];
            while (temp != cycle_start) {
                cycle_min = min(cycle_min, temp);
                temp = p[temp];
            }
            M[cycle_start] = cycle_min;
            temp = p[cycle_start];
            while (temp != cycle_start) {
                M[temp] = cycle_min;
                temp = p[temp];
            }
        }
        for (int j = (int)path.size() - 1; j >= 0; j--) {
            if (M[path[j]] == 0) {
                M[path[j]] = min(path[j], M[p[path[j]]]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        root[i] = update(root[i - 1], 1, n, M[i]);
    }

    while (q--) {
        int L, R;
        cin >> L >> R;
        int len = R - L + 1;
        double K = len / 2.0;

        int k_low = 0;
        int low = 1, high = len;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int vk = find_kth(root[L - 1], root[R], 1, n, mid);
            if (query(root[L - 1], root[R], 1, n, vk) <= K) {
                k_low = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        double min_diff = 1e18;
        int best_x = 2e9;

        auto check = [&](int X) {
            if (X < 1 || X > n) return;
            int c = query(root[L - 1], root[R], 1, n, X);
            double diff = abs(c - K);
            if (diff < min_diff - 1e-9) {
                min_diff = diff;
                best_x = X;
            } else if (abs(diff - min_diff) < 1e-9) {
                best_x = min(best_x, X);
            }
        };

        check(1);
        if (k_low >= 1) {
            int v_low = find_kth(root[L - 1], root[R], 1, n, k_low);
            check(v_low);
        }
        if (k_low + 1 <= len) {
            int v_high = find_kth(root[L - 1], root[R], 1, n, k_low + 1);
            check(v_high);
        }
        cout << best_x << "\n";
    }

    return 0;
}