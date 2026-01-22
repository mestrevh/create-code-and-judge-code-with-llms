/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int homens = 0, mulheres = 0;
    float salarioHomens = 0, salarioMulheres = 0, maiorSalario = 0;
    char sexoMaiorSalario;
    
    for (int i = 0; i < 10; i++) {
        char sexo;
        float salario;
        cin >> salario >> sexo;

        if (sexo == 'm') {
            homens++;
            salarioHomens += salario;
        } else {
            mulheres++;
            salarioMulheres += salario;
        }

        if (salario > maiorSalario) {
            maiorSalario = salario;
            sexoMaiorSalario = sexo;
        }
    }

    float mediaHomens = (homens > 0) ? salarioHomens / homens : 0;
    float mediaMulheres = (mulheres > 0) ? salarioMulheres / mulheres : 0;
    float mediaTotal = (mediaHomens + mediaMulheres) / 2;

    cout << homens << endl;
    cout << mulheres << endl;
    cout << fixed << setprecision(1) << mediaTotal << endl;
    cout << sexoMaiorSalario << endl;
    cout << fixed << setprecision(1) << mediaHomens << endl;

    return 0;
}
