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
    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = N - 1; i >= 0; i--) {
        if (i != N - 1) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}