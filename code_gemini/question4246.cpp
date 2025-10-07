/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Triangulo {
    int lado1, lado2, lado3;
    double area;
};

void calculaArea(int a, int b, int c, double *area) {
    double s = (static_cast<double>(a) + b + c) / 2.0;
    *area = std::sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Triangulo> triangulos(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> triangulos[i].lado1 >> triangulos[i].lado2 >> triangulos[i].lado3;
        calculaArea(triangulos[i].lado1, triangulos[i].lado2, triangulos[i].lado3, &triangulos[i].area);
    }

    std::sort(triangulos.begin(), triangulos.end(), [](const Triangulo& a, const Triangulo& b) {
        return a.area < b.area;
    });

    for (const auto& t : triangulos) {
        std::cout << t.lado1 << " " << t.lado2 << " " << t.lado3 << "\n";
    }

    return 0;
}
