/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int paginas_impressas;
    double percentual;
    std::cin >> paginas_impressas >> percentual;
    int total_paginas = (paginas_impressas * 100.0) / percentual;
    int paginas_faltantes = total_paginas - paginas_impressas;
    std::cout << "O documento possui " << total_paginas << " paginas\n";
    std::cout << "Ja foram impressas " << paginas_impressas << " paginas\n";
    std::cout << "Faltam " << paginas_faltantes << " paginas\n";
    return 0;
}
