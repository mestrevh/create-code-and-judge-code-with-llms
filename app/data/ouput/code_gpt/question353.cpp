/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double peso, altura;
    cin >> peso >> altura;
    double imc = peso / (altura * altura);
    
    if (imc < 17)
        cout << "muito abaixo do peso" << endl;
    else if (imc >= 17 && imc < 18.49)
        cout << "abaixo do peso" << endl;
    else if (imc >= 18.5 && imc < 24.99)
        cout << "peso normal" << endl;
    else if (imc >= 25 && imc < 29.99)
        cout << "acima do peso" << endl;
    else if (imc >= 30 && imc < 34.99)
        cout << "obesidade" << endl;
    else if (imc >= 35 && imc < 39.99)
        cout << "obesidade severa" << endl;
    else
        cout << "obesidade morbida" << endl;

    return 0;
}
