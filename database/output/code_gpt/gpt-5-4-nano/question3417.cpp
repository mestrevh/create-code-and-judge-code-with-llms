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
        if (N == -1) break;

        int cnt = 0;
        for (int i = 0; i < 1000; i++) {
            int x;
            if (!(cin >> x)) return 0;
            if (x == N) cnt++;
        }

        cout << N << " appeared " << cnt << " times\n";
    }
    return 0;
}