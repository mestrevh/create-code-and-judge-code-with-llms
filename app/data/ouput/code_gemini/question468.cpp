/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int count = 0;
    for (int i = 0; i < 5; ++i) {
        double original_price, discounted_price;
        std::cin >> original_price >> discounted_price;
        if (discounted_price <= original_price * 0.8) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
