/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string chemical, search_in;
    while (std::cin >> chemical) {
        std::cin >> search_in;
        if (search_in.find(chemical) != std::string::npos) {
            std::cout << "I'm on the empire business.\n";
        } else {
            std::cout << "HE CAN'T KEEP GETTING AWAY WITH IT!\n";
        }
    }
    return 0;
}
