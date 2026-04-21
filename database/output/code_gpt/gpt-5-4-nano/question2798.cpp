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

    vector<int> small, large;
    for (int i = 1; 1LL * i * i <= N; i++) {
        if (N % i == 0) {
            small.push_back(i);
            if (i != N / i) large.push_back(N / i);
        }
    }

    for (int x : small) cout << x << "\n";
    for (int i = (int)large.size() - 1; i >= 0; i--) cout << large[i] << "\n";
    return 0;
}