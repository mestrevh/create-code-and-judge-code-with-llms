/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<int, int> voos;
    int numero_voo, assentos;

    for (int i = 0; i < 37; ++i) {
        std::cin >> numero_voo >> assentos;
        voos[numero_voo] = assentos;
    }

    int id_cliente, voo_desejado;
    while (std::cin >> id_cliente && id_cliente != 9999) {
        std::cin >> voo_desejado;

        if (voos.count(voo_desejado) && voos[voo_desejado] > 0) {
            std::cout << id_cliente << "\n";
            voos[voo_desejado]--;
        } else {
            std::cout << "INDISPONIVEL\n";
        }
    }

    return 0;
}
