/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a(1000);
    while (true) {
        if (!cin) break;
        long long first;
        if (!(cin >> first)) break;

        if (first == -1) break;

        a[0] = first;
        for (int i = 1; i < 1000; i++) cin >> a[i];

        long long N;
        cin >> N;

        long long cnt = 0;
        for (int i = 0; i < 1000; i++) if (a[i] == N) cnt++;

        cout << N << " appeared " << cnt << " times\n";
    }

    return 0;
}