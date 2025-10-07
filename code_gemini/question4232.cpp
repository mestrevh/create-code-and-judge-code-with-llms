/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num;
    int result_gcd = 0;
    bool first_number = true;

    while (std::cin >> num && num > 0) {
        if (first_number) {
            result_gcd = num;
            first_number = false;
        } else {
            result_gcd = std::gcd(result_gcd, num);
        }
    }

    std::cout << result_gcd << std::endl;

    return 0;
}
