/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<pair<int, string>> a;
    a.reserve(N);

    for (int i = 0; i < N; i++) {
        string name;
        int t;
        cin >> name >> t;
        a.push_back({t, name});
    }

    int idx;
    cin >> idx;
    idx--;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (a[x].first > a[y].first) swap(a[x], a[y]);
        }
    }

    cout << "Naruto devera usar a shuriken " << a[idx].second << " para esta maquina.\n";
    return 0;
}