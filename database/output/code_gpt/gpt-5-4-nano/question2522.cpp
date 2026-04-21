/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> A, B;
    int x;
    for (int i = 0; i < 5; i++) {
        if (!(cin >> x)) return 0;
        A.insert(x);
    }
    for (int i = 0; i < 5; i++) {
        cin >> x;
        B.insert(x);
    }

    bool first = true;
    for (const int &v : A) {
        if (B.find(v) != B.end()) {
            if (!first) cout << ' ';
            cout << v;
            first = false;
        }
    }
    return 0;
}