/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int consumer;
    double kwh;
    int type;

    double total1 = 0.0, total2 = 0.0;
    double totalKwh = 0.0;

    while (true) {
        cout << "Digite o numero do consumidor: ";
        if (!(cin >> consumer)) return 0;
        if (consumer == 0) break;

        cout << "Digite a quantidade de KWh consumidos: ";
        cin >> kwh;

        cout << "Digite o tipo de consumidor: ";
        cin >> type;

        double price = 0.0;
        if (type == 1) price = 0.3;
        else if (type == 2) price = 0.5;
        else if (type == 3) price = 0.7;

        double cost = kwh * price;

        if (type == 1) total1 += kwh;
        else if (type == 2) total2 += kwh;

        totalKwh += kwh;

        cout << "Custo total para o consumidor " << consumer << ": R$ " << fixed << setprecision(2) << cost << "\n";
        cout << "Total de consumo acumulado: " << (long long)llround(totalKwh) << " Kwh\n";

        double media = (total1 + total2) / 2.0;
        cout << "Media de consumo dos tipos 1 e 2: " << fixed << setprecision(1) << media << " KWh\n";
    }

    return 0;
}