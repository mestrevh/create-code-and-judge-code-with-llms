/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double lado;
    cout << "Informe a medida de um dos lados do quadrado:" << endl;
    cin >> lado;
    double area = lado * lado;
    double dobro = area * 2;
    cout << "Resultado: " << area << endl;
    cout << "Dobro: " << dobro << endl;
    return 0;
}
