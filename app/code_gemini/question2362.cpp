/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int horas, minutos, segundos;
    std::cin >> horas >> minutos >> segundos;
    long long total_segundos = (long long)horas * 3600 + (long long)minutos * 60 + segundos;
    std::cout << total_segundos << std::endl;
    return 0;
}
