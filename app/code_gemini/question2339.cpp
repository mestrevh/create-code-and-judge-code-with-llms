/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <utility>

void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << "a: " << a << " b: " << b << std::endl;
    troca(&a, &b);
    std::cout << "a: " << a << " b: " << b << std::endl;
    return 0;
}
