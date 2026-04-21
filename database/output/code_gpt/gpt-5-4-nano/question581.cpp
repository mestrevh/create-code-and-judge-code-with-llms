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
    long long C;
    if (!(cin >> N >> C)) return 0;
    vector<long long> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    const long long NEG = -(1LL<<60);
    long long cash = 0;
    long long hold = NEG;

    for (int i = 0; i < N; i++) {
        long long price = P[i];
        cash = max(cash, hold + price);
        hold = max(hold, cash - (price + C));
    }

    cout << cash << "\n";
    return 0;
}