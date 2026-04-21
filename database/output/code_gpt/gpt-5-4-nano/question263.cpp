/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> a, b;
    for (int i = 0; i < 20; i++) {
        int x;
        if (!(cin >> x)) return 0;
        a.insert(x);
    }
    for (int i = 0; i < 20; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }

    vector<int> inter;
    for (int x : a) {
        if (b.count(x)) inter.push_back(x);
    }

    if (inter.empty()) {
        cout << "VAZIO";
    } else {
        for (int i = 0; i < (int)inter.size(); i++) {
            if (i) cout << "\n";
            cout << inter[i];
        }
    }
    return 0;
}