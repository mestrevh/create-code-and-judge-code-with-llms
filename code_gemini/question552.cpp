/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;
    while (N--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << "MDC(" << a << "," << b << ") = " << mdc(a, b) << std::endl;
    }
    return 0;
}
