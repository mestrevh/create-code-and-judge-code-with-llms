/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a;
    int n;
    if (!(cin >> a >> n)) return 0;

    long long limit = (long long)n * 60;

    long long t = a;
    while (t <= limit) {
        if (t == 0) {
            cout << (a - t) << "\n";
            return 0;
        }
        if (t % 13 == 0) {
            long long x = t % 60;
            if (x == 0) t += 30;
            else t -= 60;
        } else {
            t += 1;
        }
    }

    cout << "fui pedir comida mesmo\n";
    return 0;
}