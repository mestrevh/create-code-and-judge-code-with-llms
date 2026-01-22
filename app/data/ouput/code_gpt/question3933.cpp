/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

struct Suspeito {
    std::string nome;
    std::string dna;
    int fragmentosContidos = 0;
    int somaTamanhos = 0;
};

bool verificarFragmento(const std::string& dna, const std::string& fragmento) {
    return dna.find(fragmento) != std::string::npos;
}

int main() {
    int M;
    std::cin >> M;
    std::string fragmentos[3];
    
    for (int i = 0; i < 3; ++i) {
        std::cin >> fragmentos[i];
    }
    
    std::vector<Suspeito> suspeitos(M);
    std::cin.ignore();
    
    for (int i = 0; i < M; ++i) {
        std::string linha;
        std::getline(std::cin, linha);
        std::istringstream iss(linha);
        std::getline(iss, suspeitos[i].nome, ' - ');
        std::getline(iss, suspeitos[i].dna);
        
        for (const auto& fragmento : fragmentos) {
            if (verificarFragmento(suspeitos[i].dna, fragmento)) {
                suspeitos[i].fragmentosContidos++;
                suspeitos[i].somaTamanhos += fragmento.size();
            }
        }
    }

    int maxFragmentos = 0;
    int maxSoma = 0;
    std::vector<Suspeito> candidatos;

    for (const auto& suspeito : suspeitos) {
        if (suspeito.fragmentosContidos > maxFragmentos) {
            maxFragmentos = suspeito.fragmentosContidos;
            maxSoma = suspeito.somaTamanhos;
            candidatos = {suspeito};
        } else if (suspeito.fragmentosContidos == maxFragmentos) {
            if (suspeito.somaTamanhos > maxSoma) {
                maxSoma = suspeito.somaTamanhos;
                candidatos = {suspeito};
            } else if (suspeito.somaTamanhos == maxSoma) {
                candidatos.push_back(suspeito);
            }
        }
    }

    if (candidatos.size() == 1) {
        std::cout << "X reponsavel por essa atrocidade foi " << candidatos[0].nome << "!" << std::endl;
    } else {
        std::cout << "Nao pegamos x pilantra desse vez..." << std::endl;
    }

    return 0;
}
