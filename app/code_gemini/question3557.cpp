/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int dividendo, divisor;
    while (std::cin >> dividendo >> divisor) {
        int quociente = 0;
        if (divisor != 0) {
            unsigned int dividendo_abs = dividendo < 0 ? -dividendo : dividendo;
            unsigned int divisor_abs = divisor < 0 ? -divisor : divisor;
            while (dividendo_abs >= divisor_abs) {
                dividendo_abs -= divisor_abs;
                quociente++;
            }
            if ((dividendo < 0) != (divisor < 0)) {
                quociente = -quociente;
            }
        }
        std::cout << quociente << std::endl;
    }
    return 0;
}
