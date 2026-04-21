/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string item;
    long double total = 0.0;
    string bestName;
    long double bestPrice = -1.0;

    while (cin >> item) {
        string lower = item;
        for (char &c : lower) c = (char)tolower((unsigned char)c);

        if (lower == "fim") break;

        long double price;
        cin >> price;

        total += price;

        if (price > bestPrice) {
            bestPrice = price;
            bestName = item;
        }
    }

    for (char &c : bestName) c = (char)toupper((unsigned char)c);

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << (double)total << "\n" << bestName << "\n";
    return 0;
}