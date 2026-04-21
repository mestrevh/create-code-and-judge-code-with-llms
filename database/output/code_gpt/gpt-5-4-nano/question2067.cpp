/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    long long Y;
    if (!(cin >> X >> Y)) return 0;

    long long cnt = 0;
    for (int i = 0; i < X; i++) {
        long long v;
        cin >> v;
        if (v == Y) cnt++;
    }

    cout << cnt;
    return 0;
}