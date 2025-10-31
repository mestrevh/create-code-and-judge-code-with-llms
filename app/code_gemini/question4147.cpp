/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a > b && a > c) {
        std::cout << "O vencedor é Introducao a Programacao com um total de " << a << " votos E O HEXA VEIO.\n";
    } else if (b > a && b > c) {
        std::cout << "O vencedor é Introducao a Computacao com um total de " << b << " votos.\n";
    } else if (c > a && c > b) {
        std::cout << "O vencedor é Calculo 6 com um total de " << c << " votos.\n";
    } else {
        std::cout << "Empate.\n";
    }
    return 0;
}
