/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void fibonacci(int n) {
    long long a = 1, b = 1;

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            std::cout << a << std::endl;
        } else {
            std::cout << b << std::endl;
            long long temp = a + b;
            a = b;
            b = temp;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    fibonacci(n);
    return 0;
}
