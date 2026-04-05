/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int hh, mm;
    if (!(cin >> hh >> mm)) return 0;

    bool isPM = hh >= 12;
    int hh12;
    if (hh == 0) hh12 = 12;
    else if (hh > 12) hh12 = hh - 12;
    else hh12 = hh;

    cout << setw(2) << setfill('0') << hh12 << "\n";
    cout << setw(2) << setfill('0') << mm << "\n";
    cout << (isPM ? "pm" : "am") << "\n";
    return 0;
}