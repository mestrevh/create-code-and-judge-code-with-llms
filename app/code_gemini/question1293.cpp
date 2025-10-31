/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int calculate_height(int n, int k) {
    if (k == 1) {
        return 0;
    }
    return 1 + calculate_height(n, k / n);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k;
    std::cin >> n;
    std::cin >> k;
    std::cout << calculate_height(n, k) << std::endl;
    return 0;
}
