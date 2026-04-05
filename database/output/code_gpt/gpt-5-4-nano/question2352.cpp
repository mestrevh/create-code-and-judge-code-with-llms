/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void transformaPares(list<long long>& L) {
    for (auto it = L.begin(); it != L.end(); ++it) {
        if (*it % 2 == 0) *it += 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    list<long long> L(n);
    for (auto &x : L) cin >> x;

    transformaPares(L);

    for (auto it = L.begin(); it != L.end(); ++it) {
        if (it != L.begin()) cout << "\n";
        cout << *it;
    }
    return 0;
}