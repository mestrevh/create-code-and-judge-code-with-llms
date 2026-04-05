/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while ( (cin >> n) ) {
        if (n == 0) break;

        int status[32];
        for (int b = 0; b < 32; b++) status[b] = -1;

        auto apply_set = [&](int i){
            status[i] = 1;
        };
        auto apply_clear = [&](int i){
            status[i] = 0;
        };

        auto apply_or = [&](int i, int j){
            if (status[i] != -1 && status[j] != -1) status[i] = (status[i] | status[j]);
            else if (status[i] == -1) {
                if (status[j] == 0) status[i] = 0;
                else if (status[j] == 1) status[i] = 1;
            }
            else {
                if (status[i] == 0 && status[j] != -1) status[i] = status[j] ; // 0 | x = x
            }
        };

        auto apply_and = [&](int i, int j){
            if (status[i] != -1 && status[j] != -1) status[i] = (status[i] & status[j]);
            else if (status[i] == -1) {
                if (status[j] == 0) status[i] = 0;
                else if (status[j] == 1) status[i] = 1;
            }
            else {
                if (status[i] == 1 && status[j] != -1) status[i] = status[j]; // 1 & x = x
            }
        };

        for (int k = 0; k < n; k++) {
            string op;
            cin >> op;
            if (op == "SET") {
                int i; cin >> i;
                apply_set(i);
            } else if (op == "CLEAR") {
                int i; cin >> i;
                apply_clear(i);
            } else if (op == "OR") {
                int i, j; cin >> i >> j;
                apply_or(i, j);
            } else if (op == "AND") {
                int i, j; cin >> i >> j;
                apply_and(i, j);
            }
        }

        for (int b = 31; b >= 0; b--) {
            if (status[b] == -1) cout << '?';
            else cout << (status[b] ? '1' : '0');
        }
        cout << "\n";
    }
    return 0;
}