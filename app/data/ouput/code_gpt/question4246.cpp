/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Triangulo {
    int a, b, c;
    double area;

    void calculaArea() {
        double s = (a + b + c) / 2.0;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

bool compare(const Triangulo &t1, const Triangulo &t2) {
    return t1.area < t2.area;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Triangulo> triangulos(n);

    for (int i = 0; i < n; i++) {
        std::cin >> triangulos[i].a >> triangulos[i].b >> triangulos[i].c;
        triangulos[i].calculaArea();
    }

    std::sort(triangulos.begin(), triangulos.end(), compare);

    for (const auto &t : triangulos) {
        std::cout << t.a << " " << t.b << " " << t.c << std::endl;
    }
    return 0;
}
