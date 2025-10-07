/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string str1, str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);

    if (str1 == str2) {
        std::cout << "IGUAIS" << std::endl;
    } else {
        std::cout << "DIFERENTES" << std::endl;
    }

    return 0;
}
