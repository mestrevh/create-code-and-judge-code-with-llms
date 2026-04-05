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
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool ok = true;
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            if (x == 0) ok = false;
        }
        if (ok) ans++;
    }
    
    cout << ans << "\n";
    return 0;
}