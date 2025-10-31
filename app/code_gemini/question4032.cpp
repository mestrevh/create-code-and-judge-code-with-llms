/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    bool is_fib[46] = {false};
    is_fib[0] = true;
    is_fib[1] = true;
    is_fib[2] = true;
    is_fib[3] = true;
    is_fib[5] = true;
    is_fib[8] = true;
    is_fib[13] = true;
    is_fib[21] = true;
    is_fib[34] = true;

    int n;
    std::cin >> n;

    int temp_n = n;
    int sum = 0;
    while (temp_n > 0) {
        sum += temp_n % 10;
        temp_n /= 10;
    }

    if (sum <= 45 && is_fib[sum]) {
        std::cout << "Sim\n";
    } else {
        std::cout << "Nao\n";
    }

    return 0;
}
