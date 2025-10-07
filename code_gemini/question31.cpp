/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int horas, minutos;
    std::cin >> horas;
    std::cin >> minutos;
    int total_minutos = (horas * 60) + minutos;
    std::cout << total_minutos << " minutos." << std::endl;
    return 0;
}
