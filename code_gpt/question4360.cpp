/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double nota;
    cin >> nota;
    cout << fixed << setprecision(1) << "Nota digitada: " << nota << endl;
    if (nota < 0 || nota > 10) {
        cout << "A nota nao esta no intervalo [0,10]" << endl;
    }
    return 0;
}
