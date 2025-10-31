/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n;
    std::cin >> m >> n;

    std::vector<int> arr(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> arr[i];
    }

    if (n > m) {
        n = m;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }

        std::cout << "[";
        for (int k = 0; k < m; ++k) {
            std::cout << arr[k];
            if (k < m - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }

    return 0;
}
