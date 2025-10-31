/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
public:
    SegmentTree(int n) : n(n), tree(4 * n, 0) {}

    void build(const vector<int> &arr) {
        build(1, 0, n - 1, arr);
    }

    void update(int idx, int value) {
        update(1, 0, n - 1, idx, value);
    }

    int queryEven(int l, int r) {
        return query(1, 0, n - 1, l, r, true);
    }

    int queryOdd(int l, int r) {
        return query(1, 0, n - 1, l, r, false);
    }

private:
    int n;
    vector<int> tree;

    void build(int node, int start, int end, const vector<int> &arr) {
        if (start == end) {
            tree[node] = arr[start] % 2 == 0 ? 1 : 0;
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, arr);
            build(2 * node + 1, mid + 1, end, arr);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value % 2 == 0 ? 1 : 0;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, value);
            } else {
                update(2 * node + 1, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int l, int r, bool isEven) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return isEven ? tree[node] : (end - start + 1 - tree[node]);
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r, isEven) + query(2 * node + 1, mid + 1, end, l, r, isEven);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree st(n);
    st.build(arr);

    int q;
    cin >> q;
    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 0) {
            st.update(a - 1, b);
        } else if (type == 1) {
            cout << st.queryEven(a - 1, b - 1) << endl;
        } else if (type == 2) {
            cout << st.queryOdd(a - 1, b - 1) << endl;
        }
    }

    return 0;
}
