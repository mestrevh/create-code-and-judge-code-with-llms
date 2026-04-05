/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    if (!(cin >> N >> M)) return 0;
    map<int,int> cnt;
    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        cnt[a]++;
    }
    int ans = 0;
    for (auto &p : cnt) ans = max(ans, p.second / N);
    cout << ans << "\n";
    return 0;
}