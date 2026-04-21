/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Country {
    int id;
    int gold, silver, bronze;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<Country> c(N + 1);
    for (int i = 1; i <= N; i++) {
        c[i] = {i, 0, 0, 0};
    }

    for (int i = 0; i < M; i++) {
        int O, P, B;
        cin >> O >> P >> B;
        c[O].gold++;
        c[P].silver++;
        c[B].bronze++;
    }

    vector<Country> v;
    v.reserve(N);
    for (int i = 1; i <= N; i++) v.push_back(c[i]);

    sort(v.begin(), v.end(), [](const Country& a, const Country& b) {
        if (a.gold != b.gold) return a.gold > b.gold;
        if (a.silver != b.silver) return a.silver > b.silver;
        if (a.bronze != b.bronze) return a.bronze > b.bronze;
        return a.id < b.id;
    });

    for (int i = 0; i < N; i++) {
        cout << v[i].id << "\n";
    }

    return 0;
}