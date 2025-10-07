/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string carne, paoAlho, bebidasAdultos, bebidasCrianças;
    int kids, adults;
    double total = 0.0;

    cin >> carne >> paoAlho >> bebidasAdultos >> bebidasCrianças >> kids >> adults;

    double precoBovino = 32.0, precoFrango = 18.0, precoSuino = 15.0;
    double precoCerveja = 8.0, precoRefrigerante = 6.0;

    if (carne == "C") {
        total += (adults * 0.2 + kids * 0.2) * 1000 * precoBovino; 
        total += adults * 0.1 * 1000 * precoFrango; 
        total += adults * 0.1 * 1000 * precoSuino;
    } else if (carne == "BF") {
        total += (adults * 0.25 * 1000) * precoBovino; 
        total += adults * 0.15 * 1000 * precoFrango; 
    } else if (carne == "BS") {
        total += (adults * 0.25 * 1000) * precoBovino; 
        total += adults * 0.15 * 1000 * precoSuino; 
    } else {
        cout << "Opção inválida." << endl;
        return 0;
    }

    total += (adults * (bebidasAdultos == "S" ? 2 * precoCerveja : 0));
    total += (kids * (bebidasCrianças == "S" ? 0.5 * precoRefrigerante : 0));

    if (paoAlho == "N") {
        total *= 0.98;
    }

    cout << fixed << setprecision(2) << "R$: " << total << endl;

    return 0;
}
