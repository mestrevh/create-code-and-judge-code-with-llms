/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string chemical;
    std::string source;
    while (std::cin >> chemical >> source) {
        if (source.find(chemical) != std::string::npos) {
            std::cout << "I'm on the empire business.\n";
        } else {
            std::cout << "HE CAN'T KEEP GETTING AWAY WITH IT!\n";
        }
    }
    return 0;
}
