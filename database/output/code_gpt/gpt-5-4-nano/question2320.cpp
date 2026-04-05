/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long factRec(long long n) {
    if (n <= 1) return 1;
    return n * factRec(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> ys;
    long long y;
    while (cin >> y) ys.push_back(y);

    bool extra = false;
    long long sumY = 0;
    for (long long v : ys) sumY += v;
    if (sumY > 100) extra = true;

    for (long long v : ys) {
        long long val = factRec(v);
        if (val < 50) val *= 2;
        cout << val << "\n";
    }
    if (extra) cout << "WildCats, get the head in the game!\n";
    return 0;
}