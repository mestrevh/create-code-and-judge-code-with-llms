/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A;
    int N;
    if (!(cin >> A)) return 0;
    cin >> N;

    long long needed = 40000000LL;
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        long long F;
        cin >> F;
        if (F * A >= needed) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}