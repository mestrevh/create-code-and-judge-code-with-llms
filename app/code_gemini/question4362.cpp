/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Pedido {
    int mesa;
    std::string prato;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<Pedido> pedidos;
    std::string comando;

    while (std::cin >> comando && comando != "Fechando") {
        if (comando == "prato") {
            int numero_mesa;
            std::string nome_prato;
            
            std::cin >> numero_mesa;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, nome_prato);
            
            pedidos.push_back({numero_mesa, nome_prato});
        } else if (comando == "clima") {
            std::string tipo_clima;
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, tipo_clima);
            
            if (tipo_clima == "Mare alta") {
                std::cout << "Retire os cliente e mesas 21 22 23 24 25 26\n";
            } else if (tipo_clima == "Mare baixa") {
                std::cout << "prepare as mesas 21 22 23 24 25 26\n";
            } else if (tipo_clima == "chuva leve" || tipo_clima == "chuva baixa") {
                std::cout << "Retire os cliente das mesas 13 14 15 16 17 18 19 20\n";
            } else if (tipo_clima == "chuva") {
                std::cout << "Retire os clientes das mesas 13 14 15 16 17 18 19 20 21 22 23 24 25 26\n";
            } else if (tipo_clima == "Tempestade") {
                std::cout << "Retire os clientes e mesas 13 14 15 16 17 18 19 20 21 22 23 24 25 26\n";
            } else if (tipo_clima == "Armagedom") {
                std::cout << "Pawb allan, y gweddill yn cael eu tanio\n";
            }
        }
    }

    for (size_t i = 0; i < pedidos.size(); ++i) {
        std::cout << "Pedido " << i + 1 << " ,mesa " << pedidos[i].mesa << " ,prato: " << pedidos[i].prato << "\n";
    }

    std::cout << "tchau\n";

    return 0;
}
