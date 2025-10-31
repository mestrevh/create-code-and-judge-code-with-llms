/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string verbo;
    std::cin >> verbo;

    std::string terceiroPessoa = verbo;
    std::string gerundio = verbo;

    if (terceiroPessoa.back() == 'r') {
        terceiroPessoa.pop_back();
    }

    if (gerundio.back() == 'r') {
        gerundio.pop_back();
        gerundio += "ndo";
    }

    std::cout << terceiroPessoa << " " << gerundio << std::endl;

    return 0;
}
