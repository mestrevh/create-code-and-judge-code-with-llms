/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int tempo, velocidade;
    cout << "Digite o tempo gasto (em horas) e a velocidade media (em km/h):" << endl;
    cin >> tempo >> velocidade;
    double distancia = tempo * velocidade;
    double litros = distancia / 12.0;
    cout << fixed << setprecision(6);
    cout << "Quantidade de litros gastos na viagem: " << litros << endl;
    return 0;
}
