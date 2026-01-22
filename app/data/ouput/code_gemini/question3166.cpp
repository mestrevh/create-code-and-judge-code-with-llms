/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int calculate_y(int x) {
    return (x - 1) * (x - 1);
}

int main() {
    int x;
    std::cin >> x;
    int y = calculate_y(x);
    std::cout << y << std::endl;
    return 0;
}
