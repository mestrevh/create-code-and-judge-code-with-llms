/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int sea[101][101] = {0};

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int xi, xf, yi, yf;
        std::cin >> xi >> xf >> yi >> yf;

        for (int x = xi; x < xf; ++x) {
            for (int y = yi; y < yf; ++y) {
                sea[x][y] = 1;
            }
        }
    }

    int total_area = 0;
    for (int x = 1; x <= 100; ++x) {
        for (int y = 1; y <= 100; ++y) {
            total_area += sea[x][y];
        }
    }

    std::cout << total_area << std::endl;

    return 0;
}
