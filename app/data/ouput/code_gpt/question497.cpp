/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    double audiencia[5];
    double soma = 0.0;
    string programas[5] = {"NOVELA", "FUTEBOL", "FILME", "FILME", "NOVELA"}; 
    int maiorIndex = 0;

    for (int i = 0; i < 5; i++) {
        cin >> audiencia[i];
        soma += audiencia[i];
        if (audiencia[i] > audiencia[maiorIndex]) {
            maiorIndex = i;
        }
    }

    double media = soma / 5.0;
    cout << fixed << setprecision(2) << media << endl;
    cout << programas[maiorIndex] << endl;

    return 0;
}
