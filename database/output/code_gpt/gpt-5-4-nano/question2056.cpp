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

    vector<long long> even, odd;
    even.reserve(N);
    odd.reserve(N);

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<long long>());

    for (auto x : even) cout << x << "\n";
    for (auto x : odd) cout << x << "\n";

    return 0;
}