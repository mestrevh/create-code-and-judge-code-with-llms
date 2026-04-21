/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    const double priceBreadPack = 4.15;
    const int breadPackSlices = 23;

    const double priceCheesePack = 3.89;
    const int cheesePackSlices = 8;

    long long needBread = 2 * n;
    long long needCheese = n;

    long long breadPacks = (needBread + breadPackSlices - 1) / breadPackSlices;
    long long cheesePacks = (needCheese + cheesePackSlices - 1) / cheesePackSlices;

    double total = breadPacks * priceBreadPack + cheesePacks * priceCheesePack;

    cout << fixed << setprecision(2) << total;
    return 0;
}