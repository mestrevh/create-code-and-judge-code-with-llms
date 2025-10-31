/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        auto lo = lower_bound(d.begin(), d.end(), x) - d.begin();
        auto hi = upper_bound(d.begin(), d.end(), x) - d.begin() - 1;

        cout << lo << " " << hi << endl;
    }
    
    return 0;
}
