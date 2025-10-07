/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }

    int t;
    std::cin >> t;
    while (t--) {
        int x, y, l;
        std::string s;
        std::cin >> x >> y >> s >> l;

        int r = x - 1;
        int c = y - 1;

        int dr = 0;
        int dc = 0;

        if (s == "cima") {
            dr = -1;
        } else if (s == "baixo") {
            dr = 1;
        } else if (s == "esquerda") {
            dc = -1;
        } else if (s == "direita") {
            dc = 1;
        }

        int total_cost = 0;
        int current_r = r + dr;
        int current_c = c + dc;

        while (current_r >= 0 && current_r < n && current_c >= 0 && current_c < m) {
            if (grid[current_r][current_c] == '#') {
                total_cost += 1;
            } else {
                total_cost += 2;
            }
            current_r += dr;
            current_c += dc;
        }

        if (l > total_cost + 2) {
            std::cout << "O amor está no ar!\n";
        } else {
            std::cout << "Vou voltar pra Limoeiro...\n";
        }
    }

    return 0;
}
