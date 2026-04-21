/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

void saudacoes(std::string nome) {
    std::cout << "Olá, " << nome << "! Seja bem-vindo\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string nome;
    if (std::getline(std::cin, nome)) {
        if (!nome.empty() && nome.back() == '\r') {
            nome.pop_back();
        }
        saudacoes(nome);
    }

    return 0;
}