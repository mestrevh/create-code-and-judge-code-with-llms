/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

void inverte_linhas() {
    std::string linha;
    if (std::getline(std::cin, linha)) {
        inverte_linhas();
        std::cout << linha << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    inverte_linhas();
    return 0;
}
