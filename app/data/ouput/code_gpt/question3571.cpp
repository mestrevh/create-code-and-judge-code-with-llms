/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double altura, raio;
    cin >> altura >> raio;

    double area = 2 * M_PI * raio * altura;
    double litros = area / 3.0;
    int latas = ceil(litros / 5.0);
    double custo = latas * 20.0;

    cout << fixed << setprecision(2);
    cout << "custo = R$ " << custo << endl;
    cout << "quantidade de latas = " << latas << endl;

    return 0;
}
