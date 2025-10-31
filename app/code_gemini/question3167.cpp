/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int findMax(int a, int b) {
    return a * (a > b) + b * (b >= a);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cin >> a >> b;
    std::cout << findMax(a, b) << std::endl;
    return 0;
}
