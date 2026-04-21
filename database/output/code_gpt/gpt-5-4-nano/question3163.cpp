/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    if (!(cin >> a >> b)) return 0;

    if (b == 0) {
        return 0;
    }

    long long x = llround(pow((long double)a, 1.0L / (long double)b));
    while (pow((long double)x, (long double)b) < (long double)a) x++;
    while (x > 0 && pow((long double)x, (long double)b) > (long double)a) x--;

    cout << x << "\n";
    return 0;
}