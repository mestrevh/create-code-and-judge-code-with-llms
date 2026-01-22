/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int idade_canina;
    std::string porte;
    std::cin >> idade_canina >> porte;
    if (porte == "pequeno") {
        std::cout << idade_canina * 5 << std::endl;
    } else if (porte == "medio") {
        std::cout << idade_canina * 7 << std::endl;
    } else if (porte == "grande") {
        std::cout << idade_canina * 9 << std::endl;
    }
    return 0;
}
