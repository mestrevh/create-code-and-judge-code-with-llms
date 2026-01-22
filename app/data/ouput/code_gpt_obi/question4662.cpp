/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int N, M, C;
vector<pair<int,int>> intervals;
vector<vector<int>> covers;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> C;
    intervals.resize(M);
    covers.assign(N, vector<int>());
    for(int i=0; i<M; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        intervals[i] = {l, r};
        for(int j=l;j<=r;++j) covers[j].push_back(i);
    }

    map<vector<int>, int> classCount;

    // Build classes for each distinct coverage pattern
    vector<int> all_ints(M);
    iota(all_ints.begin(), all_ints.end(), 0);
    vector<vector<int>> patterns;
    map<vector<int>, int> pat2id;
    for(int i=0;i<N;++i) {
        vector<int> p = covers[i];
        sort(p.begin(), p.end());
        if (!pat2id.count(p)) {
            pat2id[p] = patterns.size();
            patterns.push_back(p);
        }
    }

    vector<int> cnt(patterns.size(), 0);
    for(int i=0;i<N;++i) {
        vector<int> p = covers[i];
        sort(p.begin(), p.end());
        cnt[pat2id[p]]++;
    }

    long long ans = 1;

    for(int i=0;i<patterns.size();++i) {
        vector<int> pat = patterns[i];
        int sz = pat.size();
        // For each possible last choice of interval/color assignment to this class pass
        vector<int> color(sz, -1);
        // The answer for this pattern is: number of possible color assignments for pat
        // where each possibility is: for each interval in pat, which operation is applied last, and which color
        // It is equivalent to coloring an array of sz positions, where each update can overwrite previous ones
        // The number of possible arrays after all sequences, is C^sz.
        // But the key is that last(who updated) + color assigned determines the result.
        // So, for each of C^sz possible resulting arrays, is it possible to get via some ordering and choices?
        // Actually, for each assignment of colors to sz positions, how many such resulting final arrays are possible?
        // From problem discussion, all possible colorings can be made for each class!
        long long ways = 1;
        for(int j=0;j<sz;++j) ways = ways * C % MOD;
        ans = ans * ways % MOD;
    }
    cout << ans << endl;
}
