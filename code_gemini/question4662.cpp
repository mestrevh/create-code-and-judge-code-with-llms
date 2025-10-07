/*
Código criado pelo Gemini Pro 2.5
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

long long modInverse(long long n) {
    return power(n, 998244353 - 2);
}

const int MAX_M = 40404;
long long fact[MAX_M];
long long invFact[MAX_M];

void precompute_factorials() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX_M; i++) {
        fact[i] = (fact[i - 1] * i) % 998244353;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr_mod_p(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    return (((fact[n] * invFact[r]) % 998244353) * invFact[n - r]) % 998244353;
}

long long P(long long n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res = (res * (n - i)) % 998244353;
        if (res < 0) res += 998244353;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_factorials();

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
    
    vector<vector<int>> elementary_intervals_coverage;
    for (size_t i = 0; i < coords.size() - 1; ++i) {
        int mid = coords[i];
        vector<int> current_coverage;
        for (int j = 0; j < m; ++j) {
            if (intervals[j].first <= mid && intervals[j].second >= mid) {
                current_coverage.push_back(j);
            }
        }
        if (!current_coverage.empty()) {
            sort(current_coverage.begin(), current_coverage.end());
            elementary_intervals_coverage.push_back(current_coverage);
        }
    }

    vector<vector<int>> blocks_coverage;
    if (!elementary_intervals_coverage.empty()) {
        blocks_coverage.push_back(elementary_intervals_coverage[0]);
        for (size_t i = 1; i < elementary_intervals_coverage.size(); ++i) {
            if (elementary_intervals_coverage[i] != elementary_intervals_coverage[i - 1]) {
                blocks_coverage.push_back(elementary_intervals_coverage[i]);
            }
        }
    }

    int b = blocks_coverage.size();
    if (b == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> dp(m + 1, 0);
    dp[0] = 1;

    vector<bool> s_seen(m, false);
    int s_size = 0;

    for (int i = 0; i < b; ++i) {
        vector<int>& u_i = blocks_coverage[i];
        
        int t_i_count = 0;
        for (int interval_idx : u_i) {
            if (s_seen[interval_idx]) {
                t_i_count++;
            }
        }

        vector<long long> dp_new(m + 1, 0);
        for (int j = 0; j <= s_size; ++j) {
            if (dp[j] == 0) continue;

            long long inv_ncr_s_j = (s_size > 0 && s_size >=j) ? modInverse(nCr_mod_p(s_size, j)) : 1;
            
            for (int p = 0; p <= min(j, t_i_count); ++p) {
                long long ways_to_choose_p = (nCr_mod_p(t_i_count, p) * nCr_mod_p(s_size - t_i_count, j - p)) % 998244353;
                long long common_term = (dp[j] * ways_to_choose_p) % 998244353;
                if (s_size > 0) {
                   common_term = (common_term * inv_ncr_s_j) % 998244353;
                }
                
                if (p > 0) {
                    if (j < dp_new.size())
                      dp_new[j] = (dp_new[j] + common_term * p) % 998244353;
                }
                
                if (u_i.size() - p > 0) {
                    if (j + 1 < dp_new.size())
                      dp_new[j + 1] = (dp_new[j + 1] + common_term * (u_i.size() - p)) % 998244353;
                }
            }
        }
        
        for (int interval_idx : u_i) {
            if (!s_seen[interval_idx]) {
                s_seen[interval_idx] = true;
                s_size++;
            }
        }
        dp = dp_new;
    }

    long long total_configs = 0;
    for (int k = 1; k <= m; ++k) {
        if (dp[k] > 0) {
            total_configs = (total_configs + dp[k] * P(c, k)) % 998244353;
        }
    }

    cout << total_configs << endl;

    return 0;
}
