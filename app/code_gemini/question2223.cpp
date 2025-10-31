/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::cin >> s;
    if (s == "Zero") {
        std::cout << 0 << std::endl;
    } else if (s == "Um") {
        std::cout << 1 << std::endl;
    } else if (s == "Dois") {
        std::cout << 2 << std::endl;
    } else if (s == "Tres") {
        std::cout << 3 << std::endl;
    } else if (s == "Quatro") {
        std::cout << 4 << std::endl;
    } else if (s == "Cinco") {
        std::cout << 5 << std::endl;
    } else if (s == "Seis") {
        std::cout << 6 << std::endl;
    } else if (s == "Sete") {
        std::cout << 7 << std::endl;
    } else if (s == "Oito") {
        std::cout << 8 << std::endl;
    } else if (s == "Nove") {
        std::cout << 9 << std::endl;
    }
    return 0;
}
