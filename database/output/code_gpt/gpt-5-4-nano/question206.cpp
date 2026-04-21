/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C;
    long long X, Y, Z;
    if (!(cin >> A >> B >> C)) return 0;
    cin >> X >> Y >> Z;

    long long best = 0;

    auto tryOrient = [&](long long w, long long l, long long h) {
        if (h > Z) return;
        long long cntW = X / w;
        long long cntL = Y / l;
        best = max(best, cntW * cntL);
    };

    tryOrient(A, B, C);
    tryOrient(B, A, C);
    tryOrient(A, C, B);
    tryOrient(C, A, B);
    tryOrient(B, C, A);
    tryOrient(C, B, A);

    cout << best << "\n";
    return 0;
}