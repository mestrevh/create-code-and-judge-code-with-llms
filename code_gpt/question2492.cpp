/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string texto;
    std::getline(std::cin, texto);
    std::string textoInvertido = texto;
    std::reverse(textoInvertido.begin(), textoInvertido.end());
    std::cout << (texto == textoInvertido ? "True" : "False") << std::endl;
    return 0;
}
