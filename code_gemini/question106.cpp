/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n && n != 0) {
        long long a = 0;
        long long b = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                std::cout << " ";
            }
            std::cout << a;
            long long next = a + b;
            a = b;
            b = next;
        }
        std::cout << std::endl;
    }
    return 0;
}
