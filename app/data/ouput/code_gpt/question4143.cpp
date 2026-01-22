/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double num1, num2;
    char oper;

    cin >> num1 >> num2 >> oper;

    switch (oper) {
        case '+':
            cout << fixed << setprecision(2) << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
            break;
        case '-':
            cout << fixed << setprecision(2) << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
            break;
        case '*':
            cout << fixed << setprecision(2) << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << fixed << setprecision(2) << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
            } else {
                cout << "A operacao / eh invalida!" << endl;
            }
            break;
        default:
            cout << "A operacao " << oper << " eh invalida!" << endl;
            break;
    }
    
    return 0;
}
