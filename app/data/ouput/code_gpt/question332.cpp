/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string nome;
    std::getline(std::cin, nome);
    for (char &c : nome) {
        c = toupper(c);
    }
    std::cout << nome << std::endl;
    return 0;
}
