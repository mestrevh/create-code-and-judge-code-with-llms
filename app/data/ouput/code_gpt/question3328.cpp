/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int consumo;
    cin >> consumo;
    
    double valorKWh;
    if (consumo <= 99) {
        valorKWh = 1.35;
    } else if (consumo <= 299) {
        valorKWh = 1.55;
    } else if (consumo <= 574) {
        valorKWh = 1.75;
    } else {
        valorKWh = 2.15;
    }

    double total = consumo * valorKWh;
    if (consumo > 300) {
        total *= 1.1;
    }
    
    if (total < 35) {
        total = 35;
    }

    cout << fixed << setprecision(2) << total << endl;
    cout << fixed << setprecision(2) << valorKWh << endl;

    return 0;
}
