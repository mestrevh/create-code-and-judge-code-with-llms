/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

struct Funcionario {
    std::string nome;
    std::string dataNascimento;
    std::string cidadeNatal;
    int idade;
};

std::string gerarSenha(const Funcionario& f) {
    std::string senha;
    int nomeLen = std::min(5, (int)f.nome.size());
    int cidadeLen = std::min(4, (int)f.cidadeNatal.size());

    for (int i = 0; i < nomeLen; ++i) {
        senha += f.nome[i];
        if (i < 1) senha += f.dataNascimento[0];
        if (i < cidadeLen) senha += f.cidadeNatal[i];
        if (i == 0) senha += f.dataNascimento[1];
    }
    senha += std::to_string(f.idade);
    return senha;
}

int main() {
    Funcionario f;
    while (true) {
        std::getline(std::cin, f.nome);
        if (f.nome == "SAIR") break;
        std::getline(std::cin, f.dataNascimento);
        std::getline(std::cin, f.cidadeNatal);
        std::cin >> f.idade;
        std::cin.ignore();

        std::string senha = gerarSenha(f);
        std::cout << "Nome: " << f.nome << "\n";
        std::cout << "Data de Nascimento: " << f.dataNascimento << "\n";
        std::cout << "Cidade Natal: " << f.cidadeNatal << "\n";
        std::cout << "Idade: " << f.idade << " anos\n";
        std::cout << "Senha: " << senha << "\n\n";
    }
    return 0;
}
