/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double n;
    if (std::cin >> n) {
        if (n >= 0.0 && n <= 10.0) {
            std::cout << "valida" << std::endl;
        } else {
            std::cout << "invalida" << std::endl;
        }
    }
    
    return 0;
}