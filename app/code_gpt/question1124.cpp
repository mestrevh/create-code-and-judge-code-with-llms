/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string A, B;
    std::getline(std::cin, A);
    std::getline(std::cin, B);
    
    // Converter strings para números usando o tipo `__int128`
    __int128 a = std::stoll(A);
    __int128 b = std::stoll(B);
    
    // Calcular o produto
    __int128 product = a * b;
    
    // Imprimir o resultado
    std::cout << static_cast<long long>(product) << std::endl;
    
    return 0;
}
