/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char N, S;
    int I;
    double VI;

    std::cin >> N >> I >> S >> VI;

    if (I <= 0 || I > 120) {
        std::cout << "idade invalida!" << std::endl;
        return 0;
    }

    if ((N == 'F' || N == 'C') && I < 21) {
        std::cout << "nao pode comprar" << std::endl;
        return 0;
    }

    double discount = 0.0;

    if (S == 'F') {
        discount = 0.10;
    }

    switch (N) {
        case 'B':
            discount = std::max(discount, 0.50);
            break;
        case 'A':
            if (I < 18) {
                discount = std::max(discount, 0.20);
            } else {
                if (S == 'F') {
                    discount = std::max(discount, 0.20);
                }
            }
            break;
        case 'F':
        case 'C':
            if (I >= 21) {
                discount = std::max(discount, 0.30);
            }
            break;
        case 'I':
        case 'R':
            if (I < 16) {
                discount = std::max(discount, 0.40);
            } else {
                discount = std::max(discount, 0.30);
            }
            break;
    }

    double final_price = VI * (1.0 - discount);

    std::cout << "R$ " << std::fixed << std::setprecision(2) << final_price << std::endl;

    return 0;
}
