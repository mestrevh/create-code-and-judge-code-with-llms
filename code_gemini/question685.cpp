/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }

    int current_food = 0;
    int max_food = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'o') {
                    current_food++;
                } else if (grid[i][j] == 'A') {
                    current_food = 0;
                }
                max_food = std::max(max_food, current_food);
            }
        } else {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 'o') {
                    current_food++;
                } else if (grid[i][j] == 'A') {
                    current_food = 0;
                }
                max_food = std::max(max_food, current_food);
            }
        }
    }

    std::cout << max_food << std::endl;

    return 0;
}
