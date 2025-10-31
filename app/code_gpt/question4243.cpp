/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Paciente {
    std::string nome;
    double peso;
    double altura;
};

std::string classificarIMC(double imc) {
    if (imc < 18.5) return "Baixo peso";
    else if (imc < 25) return "Peso normal";
    else if (imc < 30) return "Sobrepeso";
    else if (imc < 35) return "Obesidade grau I";
    else if (imc < 40) return "Obesidade grau II";
    else return "Obesidade grau III";
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::vector<Paciente> pacientes(n);
    
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, pacientes[i].nome);
        std::cin >> pacientes[i].peso >> pacientes[i].altura;
        std::cin.ignore();
    }

    for (const auto& p : pacientes) {
        double imc = p.peso / (p.altura * p.altura);
        std::cout << p.nome << ":\n" << classificarIMC(imc) << "\n";
    }

    return 0;
}
