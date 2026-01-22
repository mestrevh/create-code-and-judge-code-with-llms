/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> b;
    int element;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> element;
            if (i == j) {
                if (element % x == 0) {
                    b.push_back(element);
                }
            }
        }
    }

    if (b.empty()) {
        std::cout << "NMDX" << std::endl;
    } else {
        for (size_t i = 0; i < b.size(); ++i) {
            std::cout << b[i] << (i == b.size() - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }

    return 0;
}
