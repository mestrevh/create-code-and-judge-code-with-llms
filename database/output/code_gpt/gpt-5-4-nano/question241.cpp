/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    int tc = 1;
    while ( (cin >> N >> Q) ) {
        if (N == 0 && Q == 0) break;

        const int MAXV = 10000;
        vector<int> pos(MAXV + 1, -1);

        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;
            if (0 <= x && x <= MAXV && pos[x] == -1) pos[x] = i;
        }

        cout << "CASE# " << tc++ << ":\n";
        for (int i = 0; i < Q; i++) {
            int x;
            cin >> x;
            if (0 <= x && x <= MAXV && pos[x] != -1) {
                cout << x << " found at " << pos[x] << "\n";
            } else {
                cout << x << " not found\n";
            }
        }
    }
    return 0;
}