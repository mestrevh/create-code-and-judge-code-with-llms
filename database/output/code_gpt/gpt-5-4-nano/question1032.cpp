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
    vector<int> to(N);
    for (int i = 0; i < N; i++) cin >> to[i];

    int ans = 0;
    vector<char> vis(N, 0);

    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        int cur = i;
        while (!vis[cur]) {
            vis[cur] = 1;
            cur = to[cur];
        }
        ans++;
    }

    cout << ans << "\n";
    return 0;
}