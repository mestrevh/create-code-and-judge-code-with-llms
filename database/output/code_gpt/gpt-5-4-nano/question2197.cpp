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

    vector<char> ans(N + 1, '\0');
    for (int i = 0; i < N; i++) {
        int M;
        char C;
        cin >> M >> C;
        if (1 <= M && M <= N) ans[M] = C;
    }

    for (int i = 1; i <= N; i++) cout << ans[i];
    return 0;
}