/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d;
    if (!(cin >> a >> b >> c >> d)) return 0;

    if (a < 0 || b < 0 || c < 0 || d < 0) {
        cout << "lurn maf :(\n";
        return 0;
    }

    long long buyL = 0, buyB = 0, buyE = 0, buyM = 0;

    long long bananasHome = b;
    long long orangesHome = a;
    long long eggsHome = c;
    long long milkHome = d;

    if (orangesHome > 0) {
        buyB = 2 * orangesHome;
    } else {
        buyL = bananasHome * bananasHome;
    }

    long long orangesBought = buyL;
    long long bananasBought = buyB;

    long long totalBananas = bananasHome + bananasBought;

    if (totalBananas > eggsHome) {
        buyE = orangesBought - eggsHome + max(0LL, totalBananas - orangesBought);
        long long targetEggs = max(eggsHome, orangesBought);
        if (targetEggs < totalBananas) targetEggs = totalBananas;
        buyE = targetEggs - eggsHome;
    } else {
        if (eggsHome < orangesBought) buyE = orangesBought - eggsHome;
    }

    if (eggsHome + buyE > 0) {
        long long targetMilk = 2000;
        long long currentMilk = milkHome;
        if (currentMilk < targetMilk) buyM = targetMilk - currentMilk;
    } else {
        buyM = 500;
    }

    cout << (orangesHome > 0 ? buyL + 0 : buyL) << " laranjas\n";
    cout << buyB + 0 << " bananas\n";
    cout << buyE + 0 << " ovos\n";
    cout << buyM + 0 << " mL de leite\n";

    return 0;
}