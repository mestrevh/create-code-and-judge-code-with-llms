/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int total_segundos;
    std::cin >> total_segundos;

    int dias = total_segundos / 86400;
    total_segundos %= 86400;

    int horas = total_segundos / 3600;
    total_segundos %= 3600;

    int minutos = total_segundos / 60;
    int segundos = total_segundos % 60;

    std::cout << dias << '\n';
    std::cout << horas << '\n';
    std::cout << minutos << '\n';
    std::cout << segundos << '\n';

    return 0;
}
