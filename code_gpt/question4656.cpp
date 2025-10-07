/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    std::string pares, impares, invertida;
    
    for (size_t i = 0; i < input.size(); ++i) {
        if (i % 2 == 0) {
            pares += input[i];
        } else {
            impares += input[i];
        }
    }
    
    invertida = input;
    std::reverse(invertida.begin(), invertida.end());
    
    std::cout << "Somente posições pares: " << pares << std::endl;
    std::cout << "Somente posições ímpares: " << impares << std::endl;
    std::cout << "De trás para frente: " << invertida << std::endl;
    
    return 0;
}
