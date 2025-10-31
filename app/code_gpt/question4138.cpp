/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double num1, num2;
    int op;
    cin >> num1 >> num2 >> op;
    double resultado;

    switch (op) {
        case 1:
            resultado = num1 + num2;
            break;
        case 2:
            resultado = num1 - num2;
            break;
        case 3:
            resultado = num1 * num2;
            break;
        case 4:
            if (num2 != 0)
                resultado = num1 / num2;
            else {
                cout << "Divisão por zero" << endl;
                return 0;
            }
            break;
        default:
            cout << "Operação inválida" << endl;
            return 0;
    }

    cout << fixed << setprecision(3) << resultado << endl;
    return 0;
}
