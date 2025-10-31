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
    
    if (salario > 500) {
        salario *= 1.10;
    } else if (salario > 300) {
        salario *= 1.07;
    } else {
        salario *= 1.05;
    }
    
    cout << fixed << setprecision(2) << salario << endl;
    return 0;
}
