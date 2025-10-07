/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class SegmentTree {
    vector<int> seg_sum, seg_min, arr;
    int size;

    void build(int node, int start, int end) {
        if (start == end) {
            seg_sum[node] = arr[start];
            seg_min[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            seg_sum[node] = seg_sum[2 * node + 1] + seg_sum[2 * node + 2];
            seg_min[node] = min(seg_min[2 * node + 1], seg_min[2 * node + 2]);
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            arr[idx] = val;
            seg_sum[node] = val;
            seg_min[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, val);
            } else {
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            seg_sum[node] = seg_sum[2 * node + 1] + seg_sum[2 * node + 2];
            seg_min[node] = min(seg_min[2 * node + 1], seg_min[2 * node + 2]);
        }
    }

    pair<int, int> query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return {0, numeric_limits<int>::max()};
        }
        if (l <= start && end <= r) {
            return {seg_sum[node], seg_min[node]};
        }
        int mid = (start + end) / 2;
        auto left = query(2 * node + 1, start, mid, l, r);
        auto right = query(2 * node + 2, mid + 1, end, l, r);
        return {left.first + right.first, min(left.second, right.second)};
    }

public:
    SegmentTree(vector<int> &input) {
        size = input.size();
        arr = input;
        seg_sum.resize(4 * size);
        seg_min.resize(4 * size);
        build(0, 0, size - 1);
    }

    void update(int idx, int val) {
        update(0, 0, size - 1, idx, val);
    }

    pair<int, int> query(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    SegmentTree st(arr);
    int q;
    cin >> q;
    while (q--) {
        char type;
        cin >> type;
        if (type == 'Q') {
            int L, R;
            cin >> L >> R;
            auto res = st.query(L, R);
            cout << res.first << " " << res.second << endl;
        } else if (type == 'U') {
            int p, v;
            cin >> p >> v;
            st.update(p, v);
        }
    }
    return 0;
}
