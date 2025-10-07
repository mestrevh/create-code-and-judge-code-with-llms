/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double altura, raio, custoLata, conteudoLata, cobertura, areaCilindro;

    cin >> altura >> raio >> custoLata >> conteudoLata >> cobertura;

    areaCilindro = 2 * M_PI * raio * (raio + altura);
    double litrosNecessarios = areaCilindro / cobertura;
    double latasNecessarias = ceil(litrosNecessarios / conteudoLata);
    double custoTotal = latasNecessarias * custoLata;

    cout << fixed << setprecision(6);
    cout << "Quantidade de latas: " << latasNecessarias << endl;
    cout << "Custo: R$" << custoTotal << endl;

    return 0;
}
