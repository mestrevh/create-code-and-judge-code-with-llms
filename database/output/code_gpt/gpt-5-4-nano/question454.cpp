/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string produto, sabor;
    long long qtd;
    if (!(cin >> produto >> sabor >> qtd)) return 0;

    for (char &c : produto) c = toupper((unsigned char)c);
    for (char &c : sabor) c = toupper((unsigned char)c);

    long long pricePer = 0;

    if (produto == "PIZZA") {
        if (sabor == "CALABRESA" || sabor == "MARGUERITA") pricePer = 2060;
        else pricePer = 3090;
    } else if (produto == "LASANHA") {
        if (sabor == "QUEIJO") pricePer = 1800;
        else pricePer = 2300;
    }

    long long totalCents = (pricePer * qtd) + (200 * qtd);
    cout << fixed << setprecision(2) << (totalCents / 100.0) << "\n";
    return 0;
}