/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long X, Y;
    if (!(cin >> X >> Y)) return 0;

    auto encrypt = [](long long v) -> string {
        __int128 a = (__int128)v - 1 + (__int128)v + 1;
        long long res = (long long)a;
        stringstream ss;
        ss << uppercase << hex << res;
        return ss.str();
    };

    cout << "X = " << encrypt(X) << "\n";
    cout << "Y = " << encrypt(Y) << "\n";
    return 0;
}