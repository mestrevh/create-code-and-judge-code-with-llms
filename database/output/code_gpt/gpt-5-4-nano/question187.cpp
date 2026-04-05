/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<string> names(N);
    for (int i = 0; i < N; i++) cin >> names[i];

    sort(names.begin(), names.end());
    cout << names[K - 1] << "\n";
    return 0;
}