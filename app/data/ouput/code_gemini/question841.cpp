/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double a, b, c;
    std::cin >> a >> b >> c;
    double media = (a + b + c) / 3.0;
    int contador = 0;
    if (a > media) {
        contador++;
    }
    if (b > media) {
        contador++;
    }
    if (c > media) {
        contador++;
    }
    std::cout << contador << std::endl;
    return 0;
}
