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

    int positive_answers = 0;
    for (int i = 0; i < 5; ++i) {
        std::string response;
        std::cin >> response;
        if (response == "True") {
            positive_answers++;
        }
    }

    std::cout << "Telefonou para a vitima?" << std::endl;
    std::cout << "Esteve no local do crime?" << std::endl;
    std::cout << "Mora perto da vitima?" << std::endl;
    std::cout << "Devia para a vitima?" << std::endl;
    std::cout << "Ja trabalhou com a vitima?" << std::endl;

    if (positive_answers == 2) {
        std::cout << "Suspeita" << std::endl;
    } else if (positive_answers >= 3 && positive_answers <= 4) {
        std::cout << "Cumplice" << std::endl;
    } else if (positive_answers == 5) {
        std::cout << "Assassino" << std::endl;
    } else {
        std::cout << "Inocente" << std::endl;
    }

    return 0;
}
