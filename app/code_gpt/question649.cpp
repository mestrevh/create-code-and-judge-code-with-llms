/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<int>& swaps) {
    vector<int> seq(n);
    iota(seq.begin(), seq.end(), 1);
    reverse(seq.begin(), seq.end());
    
    for (int i = 0; i < swaps.size(); ++i) {
        for (int j = 0; j < swaps[i]; ++j) {
            swap(seq[n - 1 - j], seq[n - 2 - j]);
        }
    }
    
    return seq;
}

int main() {
    int n, m;
    while (cin >> n >> m, n || m) {
        vector<int> swaps(m);
        for (int i = 0; i < m; i++) {
            cin >> swaps[i];
        }
        vector<int> result = solve(n, swaps);
        for (int i = 0; i < n; i++) {
            cout << result[i] << (i < n - 1 ? ' ' : '\n');
        }
    }
    return 0;
}
