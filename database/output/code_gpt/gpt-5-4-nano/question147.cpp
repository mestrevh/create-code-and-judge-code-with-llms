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
    long long K;
    cin >> K;

    int l = 0, r = N - 1;
    while (l < r) {
        long long s = a[l] + a[r];
        if (s == K) {
            cout << a[l] << ' ' << a[r] << "\n";
            return 0;
        }
        if (s < K) l++;
        else r--;
    }
    return 0;
}