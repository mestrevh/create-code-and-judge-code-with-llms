/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string situacao_em;
    char fez_encceja;
    int nota_encceja;
    std::string tipo_escola;
    double renda;
    char isencao_2018;

    std::cin >> situacao_em;
    std::cin >> fez_encceja;
    std::cin >> nota_encceja;
    std::cin >> tipo_escola;
    std::cin >> renda;
    std::cin >> isencao_2018;

    if (situacao_em != "CLD" && situacao_em != "CVC" && situacao_em != "CSC" && situacao_em != "NCC") {
        std::cout << "Informacao sobre ensino medio invalida" << std::endl;
        return 0;
    }

    if (isencao_2018 == 's') {
        char justificou_ausencia;
        std::cin >> justificou_ausencia;
        if (justificou_ausencia == 'n') {
            std::cout << "Infelizmente voce nao tem direito a isencao" << std::endl;
            return 0;
        }
    }

    bool eligible = false;

    // Perfil 1: Cursando último ano em escola pública
    if (situacao_em == "CVC" && tipo_escola == "PUB") {
        eligible = true;
    }

    // Perfil 2: Certificação pelo Encceja com nota mínima
    if (fez_encceja == 's' && nota_encceja >= 400) {
        eligible = true;
    }

    // Perfil 3: Concluiu em pública/bolsista integral e baixa renda
    if (situacao_em == "CLD" && (tipo_escola == "PUB" || tipo_escola == "PCB") && renda <= 1431.00) {
        eligible = true;
    }

    if (eligible) {
        std::cout << "Voce terah direito a isencao" << std::endl;
    } else {
        std::cout << "Infelizmente voce nao tem direito a isencao" << std::endl;
    }

    return 0;
}
