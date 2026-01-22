/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <cstdlib>

void equacaoredx(int c, float e) {
    std::cout << "FOCOS EM X" << std::endl;
    float a = static_cast<float>(c) / e;
    float a2 = a * a;
    float c2 = c * c;
    float b2 = a2 - c2;
    std::cout << "x^2/" << round(a2) << " + y^2/" << round(b2) << " = 1" << std::endl;
}

void equacaoredy(int c, float e) {
    std::cout << "FOCOS EM Y" << std::endl;
    float a = static_cast<float>(c) / e;
    float a2 = a * a;
    float c2 = c * c;
    float b2 = a2 - c2;
    std::cout << "x^2/" << round(b2) << " + y^2/" << round(a2) << " = 1" << std::endl;
}

int main() {
    int x1, y1, x2, y2;
    float e;
    std::cin >> x1 >> y1 >> x2 >> y2 >> e;

    if (y1 == 0 && y2 == 0) {
        int c = std::abs(x1);
        equacaoredx(c, e);
    } else if (x1 == 0 && x2 == 0) {
        int c = std::abs(y1);
        equacaoredy(c, e);
    }

    return 0;
}
