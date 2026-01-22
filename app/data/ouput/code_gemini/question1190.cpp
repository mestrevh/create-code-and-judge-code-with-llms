/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::string firstName, lastName;
    for (int i = 0; i < n; ++i) {
        std::cin >> firstName >> lastName;
        std::cout << "Cara familia " << lastName << ", sentimos muito pela tragica morte de " << firstName << "." << std::endl;
        if (lastName == "Lannister") {
            std::cout << "Os campos agora o ouvirao rugir." << std::endl;
        } else if (lastName == "Stark") {
            std::cout << "O inverno chega para todos." << std::endl;
        } else if (lastName == "Targaryen") {
            std::cout << "Voces sao superestimados mesmo." << std::endl;
        }
    }
    return 0;
}
