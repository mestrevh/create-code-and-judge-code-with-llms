/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double base_maior, base_menor, altura;
    if (cin >> base_maior >> base_menor >> altura) {
        cout << "Digite o valor da base maior: " << "\n";
        cout << "Digite o valor da base menor: " << "\n";
        cout << "Digite o valor da altura: " << "\n";

        double area = (base_maior + base_menor) * altura / 2.0;
        long long area_inteira = (long long)area;

        cout << "A parte inteira da área equivale a: " << area_inteira << endl;
    }

    return 0;
}