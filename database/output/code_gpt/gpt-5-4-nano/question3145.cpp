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
    int M;
    if (!(cin >> N)) return 0;
    cin >> M;

    vector<int> win(N + 1, 0);
    vector<int> mex(M + 2, 0);

    for (int m = 0; m <= M + 1; m++) mex[m] = m;

    for (int i = 1; i <= N; i++) {
        bool can = false;
        for (int x = 1; x <= M && x <= i; x++) {
            int last = x;
            int next = i - x;
            if (next < 0) continue;
            if (next == 0) {
                can = true;
                break;
            }
            if (win[next] == 0) {
                can = true;
                break;
            }
        }
        win[i] = can ? 1 : 0;
    }

    cout << (win[N] ? "Paula" : "Carlos") << "\n";
    return 0;
}