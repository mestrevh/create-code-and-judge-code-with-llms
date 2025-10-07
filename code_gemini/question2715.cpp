/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int soma = 0;
    for (int i = 0; i <= 500; i += 2) {
        soma += i;
    }
    std::cout << "Soma dos pares de 0 a 500: " << soma << std::endl;
    return 0;
}
