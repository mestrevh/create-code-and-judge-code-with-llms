/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    if (n < 1000 || n > 9999) {
        std::cout << "Nao pode\n";
        return 0;
    }
    int temp = n;
    while (temp > 0) {
        if (temp % 10 == 0) {
            std::cout << "Nao pode\n";
            return 0;
        }
        temp /= 10;
    }
    std::cout << "Pode\n";
    return 0;
}
