/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long c;
    cin >> n >> m >> c;

    vector<pair<int, int>> intervals(m);
    set<int> coords_set;
    coords_set.insert(1);
    coords_set.insert(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
        coords_set.insert(intervals[i].first);
        coords_set.insert(intervals[i].second + 1);
    }

    vector<int> coords(coords_set.begin(), coords_set.end());
    map<vector<int>, int> region_map;
    vector<vector<int>> region_intervals;

    for (size_t i = 0; i < coords.size() - 1; ++i) {
        int p1 = coords[i];
        int p2 = coords[i + 1] - 1;
        if (p1 > p2 || p1 > n || p2 < 1) continue;

        vector<int> current_intervals_indices;
        for (int j = 0; j < m; ++j) {
            if (intervals[j].first <= p1 && intervals[j].second >= p2) {
                current_intervals_indices.push_back(j);
            }
        }
        
        if (!current_intervals_indices.empty()) {
            sort(current_intervals_indices.begin(), current_intervals_indices.end());
            if (region_map.find(current_intervals_indices) == region_map.end()) {
                int new_idx = region_intervals.size();
                region_map[current_intervals_indices] = new_idx;
                region_intervals.push_back(current_intervals_indices);
            }
        }
    }

    int num_regions = region_intervals.size();
    if (num_regions == 0) {
        long long all_zero_is_one_config = 1;
        if (c==0) all_zero_is_one_config = 0; // Edge case, though constraints say C>=1
        
        bool covered = true;
        for(int i=1; i<=n; ++i) {
            bool pos_covered = false;
            for(int j=0; j<m; ++j) {
                if(intervals[j].first <= i && intervals[j].second >= i) {
                    pos_covered = true;
                    break;
                }
            }
            if(!pos_covered) {
                covered = false;
                break;
            }
        }
        if(!covered) all_zero_is_one_config = 0;
        
        cout << all_zero_is_one_config << endl;
        return 0;
    }

    vector<vector<int>> adj(num_regions);
    vector<int> in_degree(num_regions, 0);
    vector<vector<int>> parent_adj(num_regions);
    
    vector<pair<int, int>> edges;
    for (int i = 0; i < num_regions; ++i) {
        for (int j = 0; j < num_regions; ++j) {
            if (i == j) continue;
            if (region_intervals[i].size() > region_intervals[j].size() &&
                includes(region_intervals[i].begin(), region_intervals[i].end(),
                         region_intervals[j].begin(), region_intervals[j].end())) {
                edges.push_back({i, j});
            }
        }
    }

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        bool is_minimal = true;
        for (const auto& other_edge : edges) {
            int k = other_edge.second;
            if (other_edge.first == u && k !=v && region_intervals[k].size() > region_intervals[v].size() &&
                 includes(region_intervals[k].begin(), region_intervals[k].end(),
                          region_intervals[v].begin(), region_intervals[v].end())) {
                 is_minimal = false;
                 break;
            }
        }
        if (is_minimal) {
             adj[u].push_back(v);
             parent_adj[v].push_back(u);
             in_degree[v]++;
        }
    }

    vector<long long> s_prime_size(num_regions);
    for (int i = 0; i < num_regions; ++i) {
        set<int> child_intervals;
        for (int child : adj[i]) {
            for (int interval_idx : region_intervals[child]) {
                child_intervals.insert(interval_idx);
            }
        }
        s_prime_size[i] = region_intervals[i].size() - child_intervals.size();
    }
    
    vector<int> q;
    vector<int> rev_in_degree(num_regions, 0);
    for(int i=0; i<num_regions; ++i) {
        rev_in_degree[i] = adj[i].size();
        if(rev_in_degree[i] == 0) {
            q.push_back(i);
        }
    }

    vector<long long> dp(num_regions);
    int head = 0;
    while(head < q.size()){
        int u = q[head++];
        
        long long prod_dp = 1;
        long long prod_dp_minus_1 = 1;

        for(int child : adj[u]){
            prod_dp = (prod_dp * dp[child]) % 998244353;
            prod_dp_minus_1 = (prod_dp_minus_1 * (dp[child] - 1 + 998244353)) % 998244353;
        }

        long long term2 = (power(c, s_prime_size[u]) - 1 + 998244353) % 998244353;
        term2 = (term2 * prod_dp_minus_1) % 998244353;

        dp[u] = (prod_dp + term2) % 998244353;

        for(int p : parent_adj[u]){
            rev_in_degree[p]--;
            if(rev_in_degree[p] == 0){
                q.push_back(p);
            }
        }
    }
    
    long long ans = 1;
    for(int i = 0; i < num_regions; ++i) {
        if(in_degree[i] == 0) { 
            ans = (ans * dp[i]) % 998244353;
        }
    }
    
    cout << ans << endl;

    return 0;
}
