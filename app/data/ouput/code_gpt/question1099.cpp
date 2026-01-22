/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int base_menor, base_maior, altura;
    cin >> base_menor >> base_maior >> altura;
    
    double area = ((base_menor + base_maior) * altura) / 2.0;
    cout << fixed << setprecision(1) << area << endl;
    
    return 0;
}
