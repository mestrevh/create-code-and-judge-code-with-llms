/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double adoçante_ml, peso_rato_g, peso_pessoa_kg;
    cin >> adoçante_ml >> peso_rato_g >> peso_pessoa_kg;

    double dose_morte_pessoa = (adoçante_ml / peso_rato_g) * (peso_pessoa_kg * 1000);
    double refrigerante_l = dose_morte_pessoa / 0.1;

    cout << fixed << setprecision(1) << refrigerante_l << "L de refrigerante poderiam levar uma pessoa de " 
         << fixed << setprecision(1) << peso_pessoa_kg << "kg a morte." << endl;

    return 0;
}
