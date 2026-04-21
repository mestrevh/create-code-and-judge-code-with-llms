/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double A, B, C, D;
    if (!(cin >> A >> B >> C >> D)) return 0;

    double math1 = A * B + C / D;
    double math2 = (A * B + C) / D;

    cout << fixed << setprecision(2) << math1 << "\n" << math2 << "\n";
    return 0;
}