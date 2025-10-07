/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 1 << std::endl;
    } else {
        int count = 0;
        while (n != 0) {
            n /= 10;
            count++;
        }
        std::cout << count << std::endl;
    }
    return 0;
}
