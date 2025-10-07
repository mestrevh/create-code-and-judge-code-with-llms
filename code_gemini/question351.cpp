/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    if (b > 0) {
        return a + multiply(a, b - 1);
    }
    return multiply(-a, -b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int num1, num2;
    std::cin >> num1 >> num2;
    std::cout << multiply(num1, num2) << '\n';
    return 0;
}
