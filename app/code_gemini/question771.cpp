/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double xp, yp;
    std::cin >> xp >> yp;

    int n;
    std::cin >> n;

    int ret_count = 0;
    int cir_count = 0;

    for (int i = 0; i < n; ++i) {
        std::string tipo;
        std::cin >> tipo;

        if (tipo == "retangulo") {
            double xmin, ymin, xmax, ymax;
            std::cin >> xmin >> ymin >> xmax >> ymax;
            if (xp >= xmin && xp <= xmax && yp >= ymin && yp <= ymax) {
                ret_count++;
            }
        } else if (tipo == "circulo") {
            double xc, yc, r;
            std::cin >> xc >> yc >> r;
            r = std::abs(r);
            double dx = xp - xc;
            double dy = yp - yc;
            if (dx * dx + dy * dy <= r * r) {
                cir_count++;
            }
        }
    }

    std::cout << "Retangulos: " << ret_count << std::endl;
    std::cout << "Circulos: " << cir_count << std::endl;

    return 0;
}
