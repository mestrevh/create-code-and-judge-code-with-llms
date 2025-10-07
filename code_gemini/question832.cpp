/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char c1, c2;
    std::cin >> c1 >> c2;
    char start = std::min(c1, c2);
    char end = std::max(c1, c2);
    int diff = end - start;
    if (diff % 2 == 0) {
        char mid = (start + end) / 2;
        std::cout << mid << '\n';
    } else {
        char mid1 = (start + end) / 2;
        char mid2 = mid1 + 1;
        std::cout << mid1 << '\n';
        std::cout << mid2 << '\n';
    }
    return 0;
}
