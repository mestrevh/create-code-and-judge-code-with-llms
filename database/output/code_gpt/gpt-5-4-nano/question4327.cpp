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
    while ( (cin >> X >> Y) ) {
        if (X == 0 && Y == 0) break;
        vector<long long> a;
        a.reserve(1);
        long long d;
        while (cin >> d) {
            if (d == 0) break;
            a.push_back(d);
        }

        int n = (int)a.size();
        long long L = Y;
        long long R = X - Y;

        int lidx = lower_bound(a.begin(), a.end(), L) - a.begin();
        int ridx = upper_bound(a.begin(), a.end(), R) - a.begin() - 1;

        if (lidx <= ridx) {
            cout << (lidx + 1) << " " << (ridx + 1) << "\n";
        } else {
            cout << "0 0\n";
        }
    }
    return 0;
}