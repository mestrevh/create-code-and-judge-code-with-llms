/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

void ajudearachel(float troco) {
    int troco_em_centavos = round(troco * 100);

    int notas_valores[] = {5000, 2000, 1000, 500, 200};
    int moedas_valores[] = {100, 50, 25, 10, 5};

    int num_notas = 0;
    int num_moedas = 0;

    for (int valor : notas_valores) {
        num_notas += troco_em_centavos / valor;
        troco_em_centavos %= valor;
    }

    for (int valor : moedas_valores) {
        num_moedas += troco_em_centavos / valor;
        troco_em_centavos %= valor;
    }

    std::cout << num_notas << " notas e " << num_moedas << " moedas" << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double pedido, pago;
    std::cin >> pedido >> pago;

    double troco = pago - pedido;

    std::cout << std::fixed << std::setprecision(2) << troco << std::endl;

    ajudearachel(troco);

    return 0;
}
