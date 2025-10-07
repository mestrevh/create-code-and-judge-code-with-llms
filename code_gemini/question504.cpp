/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long total_sum = 0;
    int num;

    for (int i = 0; i < 5; ++i) {
        std::cin >> num;
        if (num > 0 && num % 3 == 0) {
            total_sum += factorial(num);
        }
    }

    std::cout << total_sum << std::endl;

    return 0;
}
