/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::cout << std::fixed << std::setprecision(1);

    if (n == 0) {
        std::cout << "[]\n";
        return 0;
    }

    std::vector<double> jumps;
    double max_so_far = std::numeric_limits<double>::lowest();

    for (int i = 0; i < n; ++i) {
        double current_jump;
        std::cin >> current_jump;
        jumps.push_back(current_jump);

        if (current_jump > max_so_far) {
            max_so_far = current_jump;
        }

        std::cout << max_so_far << "\n";
    }

    std::sort(jumps.begin(), jumps.end());

    std::cout << "[";
    for (size_t i = 0; i < jumps.size(); ++i) {
        std::cout << jumps[i];
        if (i < jumps.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    return 0;
}
