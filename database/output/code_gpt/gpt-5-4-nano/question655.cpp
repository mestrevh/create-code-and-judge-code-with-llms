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
    while ( (cin >> N) ) {
        if (N == 0) break;
        vector<int> H(N);
        for (int i = 0; i < N; i++) cin >> H[i];

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int prev = (i - 1 + N) % N;
            int next = (i + 1) % N;
            if ((H[i] > H[prev] && H[i] > H[next]) || (H[i] < H[prev] && H[i] < H[next]))
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}