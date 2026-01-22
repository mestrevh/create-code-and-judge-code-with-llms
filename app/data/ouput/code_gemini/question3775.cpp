/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

float velmed(float p1, float p5, int t) {
    return (p5 - p1) / static_cast<float>(t);
}

float media(float p1, float p2, float p3, float p4, float p5) {
    return (p1 + p2 + p3 + p4 + p5) / 5.0f;
}

float desvio(float p1, float p2, float p3, float p4, float p5, float med) {
    float sum_sq_diff = 0.0f;
    sum_sq_diff += pow(p1 - med, 2);
    sum_sq_diff += pow(p2 - med, 2);
    sum_sq_diff += pow(p3 - med, 2);
    sum_sq_diff += pow(p4 - med, 2);
    sum_sq_diff += pow(p5 - med, 2);
    return sum_sq_diff / 5.0f;
}

float desviom(float desv) {
    return desv / sqrt(4.0f);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    float p1, p2, p3, p4, p5;
    int t;
    char opt_m, opt_d;

    std::cin >> p1 >> p2 >> p3 >> p4 >> p5;
    std::cin >> t;
    std::cin >> opt_m >> opt_d;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << velmed(p1, p5, t) << std::endl;

    if (opt_m == 'm' || opt_d == 'd') {
        float med = media(p1, p2, p3, p4, p5);

        if (opt_m == 'm') {
            std::cout << med << std::endl;
        }

        if (opt_d == 'd') {
            float desv = desvio(p1, p2, p3, p4, p5, med);
            std::cout << desv << std::endl;
            std::cout << desviom(desv) << std::endl;
        }
    }

    return 0;
}
