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
    while (cin >> N) {
        if (N == 0) break;
        int mx = -1;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            if (x > mx) {
                mx = x;
                cnt = 1;
            } else if (x == mx) {
                cnt++;
            }
        }
        cout << mx << ' ' << cnt << "\n";
    }
    return 0;
}