/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double ph;
    std::cin >> ph;
    if (ph < 7.0) {
        std::cout << "Acida" << std::endl;
    } else if (ph > 7.0) {
        std::cout << "Basica" << std::endl;
    } else {
        std::cout << "Neutra" << std::endl;
    }
    return 0;
}
