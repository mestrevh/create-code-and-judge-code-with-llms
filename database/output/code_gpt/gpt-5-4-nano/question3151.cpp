/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> infected(101, 0);
    for (int a = 0; a <= 19; a++) {
        for (int b = 0; b <= 19; b++) {
            for (int c = 0; c <= 19; c++) {
                if (a + b + c != 19) continue;
                long long prod = 1LL * a * b * c;
                if (prod >= 0 && prod <= 100) infected[(int)prod] = 1;
            }
        }
    }

    int N;
    while (cin >> N) {
        if (N == -1) break;
        if (0 <= N && N <= 100 && infected[N]) cout << "INFECTADO\n";
        else cout << "SAFE\n";
    }
    return 0;
}