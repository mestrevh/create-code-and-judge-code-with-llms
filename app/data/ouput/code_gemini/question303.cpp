/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int tempo, velocidade_media;
    std::cin >> tempo;
    std::cin >> velocidade_media;
    double distancia = static_cast<double>(tempo) * velocidade_media;
    double litros = distancia / 12.0;
    std::cout << std::fixed << std::setprecision(3) << litros << std::endl;
    return 0;
}
