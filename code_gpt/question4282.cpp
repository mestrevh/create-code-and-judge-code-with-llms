/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input;
    std::string frase;
    while (std::getline(std::cin, input)) {
        if (input == "fim") break;
        if (input == "-") input = " ";
        frase += input;
    }
    
    int countPalavras = 0;
    int countLetras = 0;
    
    std::istringstream iss(frase);
    std::string palavra;
    
    while (iss >> palavra) {
        countPalavras++;
        countLetras += palavra.size();
    }
    
    std::cout << "A palavra é: " << frase << std::endl;
    std::cout << "Ela tem " << countPalavras << " palavras" << std::endl;
    std::cout << "Ela tem " << countLetras << " letras" << std::endl;

    return 0;
}
