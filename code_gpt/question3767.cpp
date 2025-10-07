/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

struct Morador {
    std::string rua;
    std::string nome;
    char sexo;
    std::string nascimento;
    bool emCasa; // true se em casa, false se em prédio
    int casa; // 1-50
    int edificio; // 1-10
    int andar; // 1-20
    int apto; // 1-2

    Morador(std::string r, std::string n, char s, std::string d, int c)
        : rua(r), nome(n), sexo(s), nascimento(d), emCasa(true), casa(c), edificio(0), andar(0), apto(0) {}
    
    Morador(std::string r, std::string n, char s, std::string d, int e, int a, int ap)
        : rua(r), nome(n), sexo(s), nascimento(d), emCasa(false), casa(0), edificio(e), andar(a), apto(ap) {}
};

std::vector<Morador> moradores;

void inserirMorador(const std::string& rua, const std::vector<std::string>& dados) {
    if (dados[0] == "c") {
        int casa = std::stoi(dados[1]);
        moradores.emplace_back(rua, dados[2], dados[3][0], dados[4], casa);
    } else {
        int edificio = std::stoi(dados[1]);
        int andar = std::stoi(dados[2]);
        int apto = std::stoi(dados[3]);
        moradores.emplace_back(rua, dados[4], dados[5][0], dados[6], edificio, andar, apto);
    }
}

void buscarMorador(const std::string& nome, const std::string& rua) {
    std::vector<Morador> encontrados;
    for (const auto& m : moradores) {
        if (m.nome == nome && m.rua == rua) {
            encontrados.push_back(m);
        }
    }
    if (encontrados.empty()) {
        std::cout << "Sem dados de \"" << nome << "\" em \"" << rua << "!\"\n";
        return;
    }
    
    std::sort(encontrados.begin(), encontrados.end(), [](const Morador& a, const Morador& b) {
        if (a.emCasa != b.emCasa) return a.emCasa; // casas antes de prédios
        if (a.emCasa) return a.casa < b.casa; // ordenar casas
        if (a.edificio != b.edificio) return a.edificio < b.edificio;
        if (a.andar != b.andar) return a.andar < b.andar;
        return a.apto < b.apto; // ordenar apartamentos
    });

    for (const auto& m : encontrados) {
        if (m.emCasa) {
            std::cout << "Casa: " << m.casa << " | Sexo: " << m.sexo << " | Nascimento: " << m.nascimento << "\n";
        } else {
            std::cout << "Edificio: " << m.edificio << " | Andar: " << m.andar << " | Numero do apt.: " << m.apto << " | Sexo: " << m.sexo << " | Nascimento: " << m.nascimento << "\n";
        }
    }
    std::cout << "Foram encontradas " << encontrados.size() << " instancias de pessoas chamadas \"" << nome << "\" em \"" << rua << "\", relatadas acima.\n";
}

int main() {
    int operacao;
    while (true) {
        std::cin >> operacao;
        std::cin.ignore();
        if (operacao == 3) {
            std::cout << "O programa sera fechado, obrigado por fazer uso dele. Lembre-se de evitar a fadiga!\n";
            break;
        }
        if (operacao < 1 || operacao > 3) {
            std::cout << "Opcao invalida. Por favor, digite uma opcao valida.\n";
            continue;
        }
        std::string rua;
        std::getline(std::cin, rua);
        if (operacao == 1) {
            std::string tipo;
            std::vector<std::string> dados(7);
            std::cin >> tipo;
            if (tipo == "c") {
                std::cin >> dados[1] >> dados[2] >> dados[3] >> dados[4];
            } else {
                std::cin >> dados[1] >> dados[2] >> dados[3] >> dados[4] >> dados[5] >> dados[6];
            }
            inserirMorador(rua, dados);
        } else if (operacao == 2) {
            std::string nome, ruaBusca;
            std::getline(std::cin, nome);
            std::getline(std::cin, ruaBusca);
            buscarMorador(nome, ruaBusca);
        }
        std::cin.ignore(); // Ignorar linha em branco
    }
    return 0;
}
