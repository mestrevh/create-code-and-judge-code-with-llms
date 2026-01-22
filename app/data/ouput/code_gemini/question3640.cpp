/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Funcionario {
    std::string nomeCompleto;
    std::string dataNascimento;
    std::string cidadeNatal;
    int idade;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 0; i < 5; ++i) {
        Funcionario f;

        getline(std::cin, f.nomeCompleto);

        if (std::cin.eof() || f.nomeCompleto == "SAIR") {
            break;
        }

        std::cin >> f.dataNascimento;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        getline(std::cin, f.cidadeNatal);
        
        std::cin >> f.idade;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string senha = "";
        std::string dia = f.dataNascimento.substr(0, 2);
        std::string mes = f.dataNascimento.substr(3, 2);

        senha += f.nomeCompleto[0];
        senha += dia[0];
        senha += f.cidadeNatal[0];
        
        senha += f.nomeCompleto[1];
        senha += dia[1];
        senha += f.cidadeNatal[1];
        
        senha += f.nomeCompleto[2];
        senha += mes[0];
        senha += f.cidadeNatal[2];

        senha += f.nomeCompleto[3];
        senha += mes[1];
        senha += f.cidadeNatal[3];

        senha += f.nomeCompleto[4];

        senha += std::to_string(f.idade);

        std::cout << "Nome: " << f.nomeCompleto << std::endl;
        std::cout << "Data de Nascimento: " << f.dataNascimento << std::endl;
        std::cout << "Cidade Natal: " << f.cidadeNatal << std::endl;
        std::cout << "Idade: " << f.idade << " anos" << std::endl;
        std::cout << "Senha: " << senha << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
