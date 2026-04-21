/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long totalPages;
    if (!(cin >> totalPages)) return 0;

    long long prev = 0;
    long long sum = 0;
    long long best = 0;

    for (int i = 0; i < 7; i++) {
        long long pos;
        cin >> pos;
        long long pagesToday = pos - prev;
        if (pagesToday < 0) pagesToday = 0;
        sum += pagesToday;
        best = max(best, pagesToday);
        prev = pos;
    }

    cout << sum << "\n" << best << "\n";
    return 0;
}