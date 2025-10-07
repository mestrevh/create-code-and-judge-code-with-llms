/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    double peso, altura, imc;
    cin >> peso >> altura;
    imc = peso / (altura * altura);

    string classificacao;
    if (imc < 18.5) classificacao = "MAGREZA";
    else if (imc <= 24.9) classificacao = "SAUDAVEL";
    else if (imc <= 29.9) classificacao = "SOBREPESO";
    else classificacao = "OBESIDADE";

    cout << fixed << setprecision(2) << imc << " " << classificacao << endl;
    return 0;
}
