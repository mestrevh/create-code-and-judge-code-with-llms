/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

#define TROCA(a, b) do { int temp = a; a = b; b = temp; } while(0)

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cin >> a >> b;
    std::cout << "a: " << a << " b: " << b << std::endl;
    TROCA(a, b);
    std::cout << "a: " << a << " b: " << b << std::endl;
    return 0;
}
