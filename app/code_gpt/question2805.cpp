/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double base_menor, base_maior, altura;
    cout << "Digite a base menor:\n";
    cin >> base_menor;
    cout << "Digite a base maior:\n";
    cin >> base_maior;
    cout << "Digite a altura:\n";
    cin >> altura;
    double area = ((base_menor + base_maior) * altura) / 2.0;
    cout << "Area do trapezio: " << fixed << setprecision(6) << area << endl;
    return 0;
}
