/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float salario;
    cin >> salario;

    if (salario < 1000) {
        salario *= 1.30;
    } else if (salario >= 1000 && salario <= 2000) {
        salario *= 1.10;
    }

    cout << fixed << setprecision(2) << salario << endl;
    return 0;
}
