/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

struct Point {
    long long x, y;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }

        bool aligned = true;
        
        long long x0 = points[0].x;
        long long y0 = points[0].y;
        long long x1 = points[1].x;
        long long y1 = points[1].y;

        for (int i = 2; i < n; ++i) {
            long long xi = points[i].x;
            long long yi = points[i].y;

            if ((y1 - y0) * (xi - x1) != (yi - y1) * (x1 - x0)) {
                aligned = false;
                break;
            }
        }

        if (aligned) {
            std::cout << "ALINHADOS\n";
        } else {
            std::cout << "NAO_ALINHADOS\n";
        }
    }

    return 0;
}
