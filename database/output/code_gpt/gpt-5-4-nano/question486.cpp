/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    bool first = true;
    long long max1 = 0, max2 = 0;

    while (cin >> x) {
        if (x == 99) break;
        if (first) {
            max1 = x;
            max2 = LLONG_MIN;
            first = false;
        } else {
            if (x > max1) {
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max2 = x;
            }
        }
    }

    cout << max2 << "\n";
    return 0;
}