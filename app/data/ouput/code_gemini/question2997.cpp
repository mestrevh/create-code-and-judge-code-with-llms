/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

struct Item {
    double valor;
    int quantidade;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, Item> lista_de_compras;
    std::string comando;

    while (std::cin >> comando) {
        if (comando == "INSERIR") {
            std::string nome;
            double valor;
            int quantidade;
            std::cin >> nome >> valor >> quantidade;
            lista_de_compras[nome] = {valor, quantidade};
        } else if (comando == "REMOVER") {
            std::string nome;
            int quantidade;
            std::cin >> nome >> quantidade;
            if (lista_de_compras.count(nome)) {
                lista_de_compras[nome].quantidade -= quantidade;
                if (lista_de_compras[nome].quantidade <= 0) {
                    lista_de_compras.erase(nome);
                }
            }
        } else if (comando == "REMOVERGRUPO") {
            double valor_limite;
            std::cin >> valor_limite;
            for (auto it = lista_de_compras.begin(); it != lista_de_compras.end(); ) {
                if (it->second.valor > valor_limite) {
                    it = lista_de_compras.erase(it);
                } else {
                    ++it;
                }
            }
        } else if (comando == "CONSULTAR") {
            double total = 0.0;
            for (const auto& par : lista_de_compras) {
                total += par.second.valor * par.second.quantidade;
            }
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "Atualmente a lista esta em R$" << total << std::endl;
        } else if (comando == "PROCURAR") {
            std::string nome;
            std::cin >> nome;
            auto it = lista_de_compras.find(nome);
            if (it != lista_de_compras.end()) {
                std::cout << it->first << std::endl;
                std::cout << std::fixed << std::setprecision(1);
                std::cout << "- " << it->second.valor << std::endl;
                std::cout << "- " << it->second.quantidade << std::endl;
            } else {
                std::cout << nome << " nao foi encontrado." << std::endl;
            }
        }
    }

    return 0;
}
