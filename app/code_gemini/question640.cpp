/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t, n;
    while (std::cin >> t >> n && (t != 0 || n != 0)) {
        int total_points = 0;
        for (int i = 0; i < t; ++i) {
            std::string name;
            int points;
            std::cin >> name >> points;
            total_points += points;
        }
        int draws = (3 * n) - total_points;
        std::cout << draws << std::endl;
    }
    return 0;
}
