/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    
    do {
        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << p[i];
        }
        cout << '\n';
    } while (next_permutation(p.begin(), p.end()));
    
    return 0;
}