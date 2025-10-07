/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
vector<int> tree[MAXN + 1], values(MAXN + 1), start(MAXN + 1), end(MAXN + 1);
vector<long long> segTree(4 * MAXN);
int timer = 0;

void dfs(int v, int p) {
    start[v] = timer++;
    for (int u : tree[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    end[v] = timer - 1;
}

void build(int node, int l, int r) {
    if (l == r) {
        segTree[node] = values[l];
    } else {
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    }
}

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        segTree[node] ^= val;
    } else {
        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(node * 2, l, mid, idx, val);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, val);
        }
        segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    }
}

long long query(int node, int l, int r, int L, int R) {
    if (L > R) return 0;
    if (L == l && R == r) return segTree[node];
    int mid = (l + r) / 2;
    return query(node * 2, l, mid, L, min(R, mid)) + query(node * 2 + 1, mid + 1, r, max(L, mid + 1), R);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    dfs(1, -1);
    build(1, 0, n - 1);

    int q;
    cin >> q;
    while (q--) {
        int type, v, k;
        cin >> type >> v;
        if (type == 1) {
            cin >> k;
            for (int i = start[v]; i <= end[v]; i++) {
                update(1, 0, n - 1, i, k);
            }
        } else {
            cout << query(1, 0, n - 1, start[v], end[v]) << endl;
        }
    }
    return 0;
}
