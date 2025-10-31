/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int total_segundos = 0;

    for (int i = 0; i < 5; ++i) {
        int minutos, segundos;
        std::cin >> minutos;
        std::cin >> segundos;
        total_segundos += minutos * 60 + segundos;
    }

    int horas_finais = total_segundos / 3600;
    int minutos_finais = (total_segundos % 3600) / 60;
    int segundos_finais = total_segundos % 60;

    std::cout << horas_finais << std::endl;
    std::cout << minutos_finais << std::endl;
    std::cout << segundos_finais << std::endl;

    return 0;
}
