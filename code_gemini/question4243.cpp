/*
Código criado pelo Gemini Pro 1.5
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(); 

    std::vector<Paciente> pacientes(n);

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, pacientes[i].nome);
        std::cin >> pacientes[i].peso >> pacientes[i].altura;
        std::cin.ignore(); 
    }

    for (int i = 0; i < n; ++i) {
        const auto& p = pacientes[i];
        double imc = p.peso / (p.altura * p.altura);

        std::cout << p.nome << ":\n";

        if (imc < 18.5) {
            std::cout << "Baixo peso";
        } else if (imc < 25.0) {
            std::cout << "Peso normal";
        } else if (imc < 30.0) {
            std::cout << "Sobrepeso";
        } else if (imc < 35.0) {
            std::cout << "Obesidade grau I";
        } else if (imc < 40.0) {
            std::cout << "Obesidade grau II";
        } else {
            std::cout << "Obesidade grau III";
        }
        
        if (i < n - 1) {
            std::cout << "\n\n";
        }
    }
    
    std::cout << std::endl;

    return 0;
}
