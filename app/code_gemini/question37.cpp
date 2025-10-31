/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int horas = n / 3600;
    int minutos = (n % 3600) / 60;
    int segundos = n % 60;
    std::cout << horas << " h " << minutos << " m " << segundos << " s\n";
    return 0;
}
