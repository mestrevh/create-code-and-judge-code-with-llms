/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

struct Node {
    long long sum;
    int min_val;
};

Node tree[4 * MAXN];
int a[MAXN];

inline Node merge_nodes(const Node& l, const Node& r) {
    return {l.sum + r.sum, std::min(l.min_val, r.min_val)};
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = {(long long)a[start], a[start]};
        return;
    }
    int mid = (start + end) >> 1;
    build(node << 1, start, mid);
    build(node << 1 | 1, mid + 1, end);
    tree[node] = merge_nodes(tree[node << 1], tree[node << 1 | 1]);
}

void update(int node, int start, int end, int pos, int val) {
    if (start == end) {
        tree[node] = {(long long)val, val};
        return;
    }
    int mid = (start + end) >> 1;
    if (pos <= mid)
        update(node << 1, start, mid, pos, val);
    else
        update(node << 1 | 1, mid + 1, end, pos, val);
    tree[node] = merge_nodes(tree[node << 1], tree[node << 1 | 1]);
}

Node query(int node, int start, int end, int l, int r) {
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) >> 1;
    if (r <= mid) {
        return query(node << 1, start, mid, l, r);
    } else if (l > mid) {
        return query(node << 1 | 1, mid + 1, end, l, r);
    } else {
        Node left_part = query(node << 1, start, mid, l, mid);
        Node right_part = query(node << 1 | 1, mid + 1, end, mid + 1, r);
        return merge_nodes(left_part, right_part);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(1, 0, n - 1);

    int q;
    if (!(cin >> q)) return 0;
    while (q--) {
        char type;
        cin >> type;
        if (type == 'Q') {
            int l, r;
            cin >> l >> r;
            Node res = query(1, 0, n - 1, l, r);
            cout << res.sum << " " << res.min_val << "\n";
        } else if (type == 'U') {
            int p, v;
            cin >> p >> v;
            update(1, 0, n - 1, p, v);
        }
    }

    return 0;
}