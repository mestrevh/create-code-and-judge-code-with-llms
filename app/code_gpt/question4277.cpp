/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    float base_maior, base_menor, altura;
    cin >> base_maior >> base_menor >> altura;
    float area = ((base_maior + base_menor) * altura) / 2;
    cout << area << endl;
    return 0;
}
