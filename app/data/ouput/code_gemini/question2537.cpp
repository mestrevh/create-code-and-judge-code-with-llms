/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int senha;
    std::cin >> senha;
    std::cout << "Digite a senha numerica:" << std::endl;
    if (senha == 1234) {
        std::cout << "ACESSO PERMITIDO" << std::endl;
    } else {
        std::cout << "ACESSO NEGADO" << std::endl;
    }
    return 0;
}
