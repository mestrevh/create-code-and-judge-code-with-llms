/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>

int main() {
    std::map<int, int> voos;
    int numero_voo, lugares;

    std::cout << "Digite o numero do voo e a quantidade de lugares disponiveis:" << std::endl;
    for (int i = 0; i < 37; i++) {
        std::cin >> numero_voo >> lugares;
        voos[numero_voo] = lugares;
    }

    while (true) {
        std::cout << "Digite o pedido de reserva:" << std::endl;
        int pedido;
        std::cin >> pedido;

        if (pedido == 9999) break;

        if (voos.find(pedido) != voos.end() && voos[pedido] > 0) {
            std::cout << "Voo " << pedido << " DISPONIVEL" << std::endl;
            voos[pedido]--;
        } else {
            std::cout << "Voo " << pedido << " INDISPONIVEL" << std::endl;
        }
    }

    return 0;
}
