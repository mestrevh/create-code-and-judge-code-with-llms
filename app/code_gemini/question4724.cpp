/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::tuple<std::string, std::string, std::string, std::string> frutas("banana", "laranja", "melancia", "morango");
    std::cout << std::get<2>(frutas) << std::endl;
    return 0;
}
