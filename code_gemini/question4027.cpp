/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double v;
    std::cin >> v;

    double d1, d2, d3;
    int w1, w2, w3;

    std::cin >> d1 >> w1;
    std::cin >> d2 >> w2;
    std::cin >> d3 >> w3;

    if (w1 || w2 || w3) {
        double total_dist = d1 + d2 + d3;
        double total_time = total_dist / v;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "O percurso sera completado em " << total_time << " segundos!" << std::endl;
    } else {
        std::cout << "Nao vai ter como completar o percurso, RIP." << std::endl;
    }

    return 0;
}
