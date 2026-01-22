/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num;
    int min_val;
    int max_val;
    bool is_first = true;

    while (std::cin >> num && num != -1) {
        if (is_first) {
            min_val = num;
            max_val = num;
            is_first = false;
        } else {
            min_val = std::min(min_val, num);
            max_val = std::max(max_val, num);
        }
        std::cout << "menor=" << min_val << "||MAIOR=" << max_val << "\n";
    }

    if (!is_first) {
        if (min_val > 0) {
            std::cout << min_val;
            for (int i = min_val + min_val; i <= max_val; i += min_val) {
                std::cout << "||" << i;
            }
            std::cout << "\n";
        } else { // min_val must be 0, as input is non-negative
            std::cout << 0 << "\n";
        }
    }

    return 0;
}
