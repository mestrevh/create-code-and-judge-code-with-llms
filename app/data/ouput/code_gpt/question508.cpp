/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int tempos[5], totalSegundos = 0;

    for(int i = 0; i < 5; i++) {
        std::cin >> tempos[i];
        totalSegundos += tempos[i];
    }

    int mediaSegundos = totalSegundos / 5;
    int totalCorrigir = mediaSegundos * 100;

    int horas = totalCorrigir / 3600;
    int minutos = (totalCorrigir % 3600) / 60;
    int segundos = totalCorrigir % 60;

    std::cout << mediaSegundos << std::endl;
    std::cout << horas << std::endl;
    std::cout << minutos << std::endl;
    std::cout << segundos << std::endl;

    return 0;
}
