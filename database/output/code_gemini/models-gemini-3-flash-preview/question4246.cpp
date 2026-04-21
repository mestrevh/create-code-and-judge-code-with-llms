/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Triangle {
    int a, b, c;
    double area;
};

void calculaArea(int a, int b, int c, double *area) {
    double s = (a + b + c) / 2.0;
    *area = std::sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<Triangle> triangles(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> triangles[i].a >> triangles[i].b >> triangles[i].c;
        calculaArea(triangles[i].a, triangles[i].b, triangles[i].c, &triangles[i].area);
    }

    std::sort(triangles.begin(), triangles.end(), [](const Triangle &t1, const Triangle &t2) {
        if (std::abs(t1.area - t2.area) < 1e-9) {
            if (t1.a != t2.a) return t1.a < t2.a;
            if (t1.b != t2.b) return t1.b < t2.b;
            return t1.c < t2.c;
        }
        return t1.area < t2.area;
    });

    for (int i = 0; i < n; ++i) {
        std::cout << triangles[i].a << " " << triangles[i].b << " " << triangles[i].c << "\n";
    }

    return 0;
}