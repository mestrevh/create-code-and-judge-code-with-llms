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
        long long sum = 0;
        int position = 1;
        while (n > 0) {
            int digit = n % 10;
            if (digit % 2 == 0) {
                sum += digit * 2 * position;
            } else {
                sum += digit * 3 * position;
            }
            n /= 10;
            position++;
        }
        std::cout << sum << '\n';
    }
    return 0;
}
