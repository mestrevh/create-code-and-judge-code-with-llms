/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string binario;
    std::cin >> binario;
    int decimal = 0;

    for (size_t i = 0; i < binario.length(); ++i) {
        if (binario[binario.length() - 1 - i] == '1') {
            decimal += pow(2, i);
        }
    }
    
    std::cout << decimal << std::endl;
    return 0;
}
