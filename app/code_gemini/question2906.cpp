/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int H, A;
    std::cin >> H >> A;

    int altura_tita = 5;
    int altura_soldado = 0;

    while (altura_tita < 50 && altura_soldado < altura_tita) {
        altura_tita += H;
        altura_soldado += A;
    }

    if (altura_tita >= 50) {
        std::cout << "Comandante, a operacao falhou!" << std::endl;
        std::cout << "altura alcancada pelo soldado: " << altura_soldado << std::endl;
    } else {
        std::cout << "Capturamos ele, comandante!" << std::endl;
        std::cout << "altura alcancada pelo tita: " << altura_tita << std::endl;
        std::cout << "altura alcancada pelo soldado: " << altura_soldado << std::endl;
    }

    return 0;
}
