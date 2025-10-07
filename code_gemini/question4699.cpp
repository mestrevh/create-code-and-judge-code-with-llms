/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

double maior_numero(double a, double b) {
    if (a > b) {
        return a;
    } else if (b > a) {
        return b;
    } else {
        return -1; 
    }
}

int main() {
    double num1, num2;
    cin >> num1 >> num2;

    double result = maior_numero(num1, num2);

    if (result == -1) {
        cout << "São iguais" << endl;
    } else {
        cout << fixed << setprecision(1) << result << endl;
    }

    return 0;
}
