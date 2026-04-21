/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    while ( (cin >> K) ) {
        if (K == 0) break;

        long long N, M;
        cin >> N >> M;

        for (int i = 0; i < K; i++) {
            long long X, Y;
            cin >> X >> Y;

            if (X == N || Y == M) {
                cout << "divisa\n";
            } else if (X < N && Y > M) {
                cout << "NE\n";
            } else if (X < N && Y < M) {
                cout << "NO\n";
            } else if (X > N && Y < M) {
                cout << "SO\n";
            } else {
                cout << "SE\n";
            }
        }
    }
    return 0;
}