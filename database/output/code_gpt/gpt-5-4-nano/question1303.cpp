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

    vector<int> A(N + 1);
    vector<array<long long, 11>> relics(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        relics[i].fill(0);
        for (int lvl = 1; lvl <= 10; lvl++) {
            long long x;
            cin >> x;
            relics[i][lvl] = x;
        }
    }

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 1);

    auto key = [&](int i) -> array<long long, 10> {
        array<long long, 10> v{};
        for (int lvl = 1; lvl <= 10; lvl++) {
            if (lvl <= A[i]) v[lvl - 1] = relics[i][lvl];
            else v[lvl - 1] = 0;
        }
        return v;
    };

    vector<array<long long, 10>> keys(N + 1);
    for (int i = 1; i <= N; i++) keys[i] = key(i);

    sort(idx.begin(), idx.end(), [&](int i, int j) {
        for (int lvl = 10; lvl >= 1; lvl--) {
            long long ci = keys[i][lvl - 1];
            long long cj = keys[j][lvl - 1];
            if (ci != cj) return ci > cj;
        }
        return i < j;
    });

    for (int id : idx) cout << id << "\n";
    return 0;
}