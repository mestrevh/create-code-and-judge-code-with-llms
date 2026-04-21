/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double usdPerGallon, brlPerLiter, exchangeRate;
    if (!(cin >> usdPerGallon >> brlPerLiter >> exchangeRate)) return 0;

    double litersPerGallon = 3.8;
    double usdToBrlPerGallon = usdPerGallon * exchangeRate;
    double usdToBrlPerLiter = usdToBrlPerGallon / litersPerGallon;

    double usdToBrlPerLiterRounded = round(usdToBrlPerLiter * 100.0) / 100.0;
    double brlPerLiterRounded = round(brlPerLiter * 100.0) / 100.0;

    cout << fixed << setprecision(2);
    cout << "Gasolina EUA: R$ " << usdToBrlPerLiterRounded << "\n";
    cout << "Gasolina Brasil: R$ " << brlPerLiterRounded << "\n";

    if (usdToBrlPerLiterRounded < brlPerLiterRounded) cout << "Mais barata nos EUA";
    else if (usdToBrlPerLiterRounded > brlPerLiterRounded) cout << "Mais barata no Brasil";
    else cout << "Igual";

    return 0;
}