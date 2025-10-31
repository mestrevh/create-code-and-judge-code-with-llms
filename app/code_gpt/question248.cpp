/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string frase;
    std::getline(std::cin, frase);
    std::string ultimaPalavra;
    std::istringstream stream(frase);
    while (stream >> ultimaPalavra);
    std::cout << ultimaPalavra << std::endl;
    return 0;
}
