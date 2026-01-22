/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    long long K, B;
    while (std::cin >> K >> B) {
        std::vector<int> digits;
        while (K > 0) {
            digits.push_back(K % B);
            K /= B;
        }
        int sum = 0;
        for (int digit : digits) {
            sum += digit;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}
