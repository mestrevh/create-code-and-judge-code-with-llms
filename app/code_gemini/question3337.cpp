/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int x0, x1, y0, y1, z0, z1;
    std::cin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
    for (int x = x0; x <= x1; ++x) {
        for (int z = z0; z <= z1; ++z) {
            int y = n - x - z;
            if (y >= y0 && y <= y1) {
                std::cout << "S\n";
                std::cout << x << " " << y << " " << z << "\n";
                return 0;
            }
        }
    }
    std::cout << "N\n";
    return 0;
}
