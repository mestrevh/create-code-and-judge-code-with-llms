/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

const long long INF = 4e18;

vector<long long> tree;
int coord_size;

void update(int node, int start, int end, int idx, long long val) {
    if (start == end) {
        tree[node] = min(tree[node], val);
        return;
    }
    int mid = start + (end - start) / 2;
    if (start <= idx && idx <= mid) {
        update(2 * node, start, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l || l > r) {
        return INF;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = start + (end - start) / 2;
    long long p1 = query(2 * node, start, mid, l, r);
    long long p2 = query(2 * node + 1, mid + 1, end, l, r);
    return min(p1, p2);
}

int get_coord_idx(const vector<long long>& coords, long long val) {
    return lower_bound(coords.begin(), coords.end(), val) - coords.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
    }

    vector<vector<pair<int, int>>> shops_at_level(n + 1);
    vector<tuple<int, int, int>> all_shops(m);
    for (int i = 0; i < m; ++i) {
        cin >> get<0>(all_shops[i]) >> get<1>(all_shops[i]) >> get<2>(all_shops[i]);
    }

    vector<long long> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + e[i];
    }
    
    vector<long long> coords;
    for (int i = 1; i <= n; ++i) {
        coords.push_back(p[i]);
    }

    for (const auto& shop_tuple : all_shops) {
        int l, s, c;
        tie(l, s, c) = shop_tuple;
        shops_at_level[l].push_back({s, c});
        coords.push_back((long long)s + p[l - 1]);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    coord_size = coords.size();
    if (coord_size > 0) {
        tree.assign(4 * coord_size, INF);
    }

    vector<long long> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        if (dp[i - 1] != INF) {
            for (const auto& shop : shops_at_level[i]) {
                long long current_cost = dp[i - 1] + shop.second;
                long long reach_val = (long long)shop.first + p[i - 1];
                int reach_idx = get_coord_idx(coords, reach_val);
                
                if (reach_idx < coord_size) {
                    update(1, 0, coord_size - 1, reach_idx, current_cost);
                }
            }
        }

        long long required_reach = p[i];
        int required_idx = get_coord_idx(coords, required_reach);
        
        if (required_idx < coord_size && !coords.empty()) {
            dp[i] = query(1, 0, coord_size - 1, required_idx, coord_size - 1);
        }
    }

    if (dp[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[n] << endl;
    }

    return 0;
}
