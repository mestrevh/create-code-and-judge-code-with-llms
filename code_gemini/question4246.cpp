/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Triangulo {
    int a, b, c;
    double area;
};

void calculaArea(int a, int b, int c, double *area) {
    double s = (a + b + c) / 2.0;
    *area = std::sqrt(s * (s - a) * (s - b) * (s - c));
}

bool comparaPorArea(const Triangulo& t1, const Triangulo& t2) {
    return t1.area < t2.area;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Triangulo> triangulos(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> triangulos[i].a >> triangulos[i].b >> triangulos[i].c;
        calculaArea(triangulos[i].a, triangulos[i].b, triangulos[i].c, &triangulos[i].area);
    }

    std::sort(triangulos.begin(), triangulos.end(), comparaPorArea);

    for (int i = 0; i < n; ++i) {
        std::cout << triangulos[i].a << " " << triangulos[i].b << " " << triangulos[i].c << "\n";
    }

    return 0;
}
