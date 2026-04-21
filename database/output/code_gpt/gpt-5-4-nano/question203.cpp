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

    vector<int> possible(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int P, D;
        cin >> P >> D;
        for (int x = P % D; x <= N; x += D) {
            if (x >= 1 && x <= N) possible[x] = 1;
        }
        if (D > 0) {
            for (int x = P; x >= 1; x -= D) {
                possible[x] = 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << possible[i] << "\n";
    }
    return 0;
}