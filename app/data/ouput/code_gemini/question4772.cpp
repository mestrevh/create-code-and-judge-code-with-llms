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

    int n;
    char c;
    std::cin >> n;
    std::cin >> c;

    if (n < 2) {
        std::cout << "Fica muito feio, meu senhor." << std::endl;
        return 0;
    }

    auto print_line = [&](int left_pos, int right_pos) {
        for (int i = 0; i < left_pos; ++i) {
            std::cout << " ";
        }
        std::cout << c;
        if (left_pos != right_pos) {
            for (int i = 0; i < right_pos - left_pos - 1; ++i) {
                std::cout << " ";
            }
            std::cout << c;
        }
        std::cout << std::endl;
    };

    int mid_point_i = (n + 1) / 2;

    // Draw X
    for (int i = 0; i <= mid_point_i; ++i) {
        print_line(i, n + 1 - i);
    }
    for (int i = mid_point_i - 1; i >= 0; --i) {
        print_line(i, n + 1 - i);
    }

    std::cout << std::endl;

    // Draw Y
    for (int i = 0; i <= mid_point_i; ++i) {
        print_line(i, n + 1 - i);
    }

    int leg_size = n / 2;
    for (int k = 0; k < leg_size; ++k) {
        print_line(mid_point_i, n + 1 - mid_point_i);
    }

    return 0;
}
