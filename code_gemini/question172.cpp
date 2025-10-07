/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>
#include <tuple>

using namespace std;

using ll = long long;

map<ll, pair<ll, int>> segments;

void split(ll p) {
    auto it = segments.upper_bound(p);
    it--; 
    
    ll seg_start = it->first;
    if (seg_start == p) {
        return;
    }
    
    ll v_start = it->second.first;
    int dir = it->second.second;
    
    ll v_p = v_start + (p - seg_start) * dir;
    
    segments[p] = {v_p, dir};
}

ll sum_ap(ll first, ll last, ll num_terms) {
    __int128_t s = (__int128_t)(first + last) * num_terms / 2;
    return (ll)s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    int m;
    cin >> n >> m;

    segments[1] = {1, 1};
    segments[n + 1] = {0, 0}; 

    for (int i = 0; i < m; ++i) {
        char type;
        ll x, y;
        cin >> type >> x >> y;

        if (type == 'I') {
            split(x);
            split(y + 1);

            auto it_start = segments.find(x);
            auto it_end = segments.find(y + 1);

            vector<tuple<ll, ll, int>> to_reverse;
            for (auto it = it_start; it != it_end; ++it) {
                ll seg_start_idx = it->first;
                ll seg_end_idx = next(it)->first;
                ll len = seg_end_idx - seg_start_idx;
                
                ll v_start = it->second.first;
                int dir = it->second.second;
                
                ll v_end = v_start + (len - 1) * dir;
                
                to_reverse.emplace_back(len, v_end, -dir);
            }

            reverse(to_reverse.begin(), to_reverse.end());

            segments.erase(it_start, it_end);

            ll current_idx = x;
            for (const auto& seg : to_reverse) {
                ll len, v_start_new, dir_new;
                tie(len, v_start_new, dir_new) = seg;
                segments[current_idx] = {v_start_new, dir_new};
                current_idx += len;
            }

        } else {
            split(x);
            split(y + 1);
            
            ll total_sum = 0;
            
            auto it_start = segments.find(x);
            auto it_end = segments.find(y + 1);
            
            for (auto it = it_start; it != it_end; ++it) {
                ll seg_start_idx = it->first;
                ll seg_end_idx = next(it)->first;
                
                ll len = seg_end_idx - seg_start_idx;

                ll v_start = it->second.first;
                int dir = it->second.second;
                
                ll v_end = v_start + (len - 1) * dir;
                
                total_sum += sum_ap(v_start, v_end, len);
            }
            cout << total_sum << "\n";
        }
    }

    return 0;
}
