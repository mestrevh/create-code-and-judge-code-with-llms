/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;

    if (q == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> v(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> v[i];
    }

    if (q <= 1) {
        std::cout << q << std::endl;
        return 0;
    }

    for (int i = 0; i < q - 1; ++i) {
        v.push_back(v[i]);
    }

    int max_len = 1;
    int current_len = 1;

    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] > v[i - 1]) {
            current_len++;
        } else {
            current_len = 1;
        }
        if (current_len > max_len) {
            max_len = current_len;
        }
    }

    std::cout << max_len << std::endl;

    return 0;
}
