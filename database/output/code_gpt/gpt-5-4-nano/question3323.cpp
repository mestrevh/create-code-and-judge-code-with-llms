/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    char X, Y;
    if (!(cin >> A >> X >> B >> Y >> C)) return 0;

    auto op = [&](int p, char c, int q) -> int {
        if (c == '^') return p & q;
        return p | q;
    };

    int result = op(A, X, B);
    result = op(result, Y, C);

    cout << result << "\n";
    return 0;
}