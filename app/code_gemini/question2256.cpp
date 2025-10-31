/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int count_occurrences(unsigned int n, int x) {
    int count = 0;
    if (n == 0 && x == 0) {
        return 1;
    }
    while (n > 0) {
        if (n % 10 == x) {
            count++;
        }
        n /= 10;
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    unsigned int n;
    int x;
    std::cin >> n >> x;
    std::cout << count_occurrences(n, x) << std::endl;
    return 0;
}
