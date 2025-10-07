/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <tuple>
#include <string>

int main() {
    std::tuple<std::string, std::string, std::string, std::string> frutas = std::make_tuple("banana", "laranja", "melancia", "morango");
    std::cout << std::get<2>(frutas) << std::endl;
    return 0;
}
