/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, y, z;
    std::cin >> x >> y >> z;

    int abs_x = std::abs(x);
    int abs_y = std::abs(y);
    int abs_z = std::abs(z);

    int min_dist = std::min({abs_x, abs_y, abs_z});

    int nx = x;
    int ny = y;
    int nz = z;

    if (min_dist == abs_x) {
        nx = -x;
    } else if (min_dist == abs_y) {
        ny = -y;
    } else {
        nz = -z;
    }

    if (nz > 0) {
        if (nx > 0 && ny > 0) {
            std::cout << 1 << std::endl;
        } else if (nx < 0 && ny > 0) {
            std::cout << 2 << std::endl;
        } else if (nx < 0 && ny < 0) {
            std::cout << 3 << std::endl;
        } else {
            std::cout << 4 << std::endl;
        }
    } else {
        if (nx > 0 && ny > 0) {
            std::cout << 5 << std::endl;
        } else if (nx < 0 && ny > 0) {
            std::cout << 6 << std::endl;
        } else if (nx < 0 && ny < 0) {
            std::cout << 7 << std::endl;
        } else {
            std::cout << 8 << std::endl;
        }
    }

    return 0;
}
