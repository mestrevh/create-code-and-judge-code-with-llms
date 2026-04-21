/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "Digite a senha numerica:" << std::endl;

    std::string senha;
    if (std::cin >> senha) {
        if (senha == "1234") {
            std::cout << "ACESSO PERMITIDO" << std::endl;
        } else {
            std::cout << "ACESSO NEGADO" << std::endl;
        }
    }

    return 0;
}