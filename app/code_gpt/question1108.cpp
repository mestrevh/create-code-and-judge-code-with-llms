/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

bool verificaEmail(const std::string& email) {
    if (email == "sair") return false;
    if (email.find('@') == std::string::npos || email.find('@') != email.rfind('@')) return false;

    size_t posArroba = email.find('@');
    size_t posPonto1 = email.find('.', posArroba);
    size_t posPonto2 = email.find('.', posPonto1 + 1);

    if (posArroba == 0 || posPonto1 == std::string::npos || posPonto2 == std::string::npos) return false;
    if (posPonto1 - posArroba < 2 || posPonto2 - posPonto1 < 2 || email.size() - posPonto2 < 2) return false;

    return true;
}

int main() {
    std::string email;
    while (std::getline(std::cin, email)) {
        if (email == "sair") break;
        std::cout << (verificaEmail(email) ? "certo" : "errado") << std::endl;
    }
    return 0;
}
