/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cin >> a >> b;
    int start = std::min(a, b);
    int end = std::max(a, b);
    long long sum = 0;
    for (int i = start; i <= end; ++i) {
        if (i > 0) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
