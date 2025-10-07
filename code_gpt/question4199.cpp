/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string chemical, search;
    while (std::getline(std::cin, chemical) && std::getline(std::cin, search)) {
        if (search.find(chemical) != std::string::npos) {
            std::cout << "I'm on the empire business." << std::endl;
        } else {
            std::cout << "HE CAN'T KEEP GETTING AWAY WITH IT!" << std::endl;
        }
    }
    return 0;
}
