/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    long long x;
    int cnt = 0;
    for (int i = 0; i < 20 && (cin >> x); i++) {
        if (x == -1) break;
        if (x == N) cnt++;
    }

    cout << N << " aparece " << cnt << " vezes";
    return 0;
}