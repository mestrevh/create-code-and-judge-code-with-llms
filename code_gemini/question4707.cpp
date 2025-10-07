/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

void saudacoes(std::string nome) {
    std::cout << "Olá, " << nome << "! Seja bem-vindo" << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string nome;
    std::cin >> nome;
    saudacoes(nome);
    return 0;
}
