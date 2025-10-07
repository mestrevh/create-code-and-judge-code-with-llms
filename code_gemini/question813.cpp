/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int test_case_count = 1;

    while (std::cin >> n && n != 0) {
        int x, y, u, v;

        std::cin >> x >> y >> u >> v;
        int intersect_x = x;
        int intersect_y = y;
        int intersect_u = u;
        int intersect_v = v;

        for (int i = 1; i < n; ++i) {
            std::cin >> x >> y >> u >> v;
            intersect_x = std::max(intersect_x, x);
            intersect_y = std::min(intersect_y, y);
            intersect_u = std::min(intersect_u, u);
            intersect_v = std::max(intersect_v, v);
        }

        std::cout << "Teste " << test_case_count++ << "\n";

        if (intersect_x < intersect_u && intersect_y > intersect_v) {
            std::cout << intersect_x << " " << intersect_y << " " << intersect_u << " " << intersect_v << "\n";
        } else {
            std::cout << "nenhum\n";
        }

        std::cout << "\n";
    }

    return 0;
}
