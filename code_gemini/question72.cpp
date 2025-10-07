/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <ios>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    if (n > 0) {
        std::vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> vec[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            std::cout << vec[i];
            if (i > 0) {
                std::cout << " ";
            }
        }
    }
    std::cout << "\n";
    return 0;
}
