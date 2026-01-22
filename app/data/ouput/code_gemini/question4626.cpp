/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int lab_num;
    std::cin >> lab_num;

    int num_maquinas = 0;
    switch (lab_num) {
        case 1:
            num_maquinas = 28;
            break;
        case 2:
            num_maquinas = 26;
            break;
        case 3:
            num_maquinas = 15;
            break;
        case 4:
            num_maquinas = 20;
            break;
    }

    std::vector<int> ids_funcionando;
    std::set<int> ids_cadastrados;

    for (int i = 0; i < num_maquinas; ++i) {
        while (true) {
            int status, id;
            std::cin >> status >> id;

            if (status != 0 && status != 1) {
                std::cout << "Identificador invalido." << std::endl;
                continue;
            }

            if (ids_cadastrados.count(id)) {
                std::cout << "ID invalido. Nao pode haver pc's iguais" << std::endl;
                continue;
            }

            ids_cadastrados.insert(id);
            if (status == 0) {
                ids_funcionando.push_back(id);
            }
            break;
        }
    }

    std::cout << "Quantidade de pessoas que podem utilizar os computadores: " << ids_funcionando.size() << std::endl;
    std::cout << "Lista de id's:" << std::endl;

    if (ids_funcionando.empty()) {
        std::cout << "Sem computadores disponiveis nesse laboratorio." << std::endl;
    } else {
        for (int id : ids_funcionando) {
            std::cout << id << std::endl;
        }
    }

    return 0;
}
