/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double height;
    int age;
    char sex;

    while (true) {
        std::cout << "Digite a altura do entrevistado:" << std::endl;
        std::cin >> height;

        if (height == 0) {
            break;
        }

        std::cout << "Digite a idade do entrevistado:" << std::endl;
        std::cin >> age;

        std::cout << "Digite o sexo do entrevistado (M ou F):" << std::endl;
        std::cin >> sex;
    }

    return 0;
}
