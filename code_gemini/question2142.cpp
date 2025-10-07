/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string adjetivo;
    std::cin >> adjetivo;
    std::string radical = adjetivo.substr(0, adjetivo.length() - 3);
    std::cout << "Aquilo que " << radical << "." << std::endl;
    return 0;
}
