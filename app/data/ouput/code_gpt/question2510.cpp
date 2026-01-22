/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

struct Presente {
    std::string nome;
    double preco;
    int preferencia;

    bool operator<(const Presente &outro) const {
        if (preferencia != outro.preferencia)
            return preferencia > outro.preferencia;
        if (preco != outro.preco)
            return preco < outro.preco;
        return nome < outro.nome;
    }
};

int main() {
    std::string dono;
    while (std::cin >> dono) {
        if (dono == "*") break;
        int Q;
        std::cin >> Q;
        std::vector<Presente> presentes(Q);
        for (int i = 0; i < Q; i++) {
            std::cin >> std::ws;
            std::getline(std::cin, presentes[i].nome);
            std::cin >> presentes[i].preco >> presentes[i].preferencia;
        }
        std::sort(presentes.begin(), presentes.end());

        std::cout << "Lista de " << dono << std::endl;
        for (const auto &presente : presentes) {
            std::cout << presente.nome << " - R$" << std::fixed << std::setprecision(2) << presente.preco << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
