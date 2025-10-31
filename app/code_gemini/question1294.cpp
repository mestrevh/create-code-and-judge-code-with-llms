/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

void decimalToBinary(long long n) {
    if (n == 0) {
        return;
    }
    decimalToBinary(n / 2);
    std::cout << n % 2;
}

long long binaryToDecimalRecursive(const std::string& s, int n) {
    if (n == 0) {
        return 0;
    }
    return binaryToDecimalRecursive(s, n - 1) * 2 + (s[n - 1] - '0');
}

long long binaryToDecimal(const std::string& binStr) {
    return binaryToDecimalRecursive(binStr, binStr.length());
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    while (N--) {
        std::string O;
        std::cin >> O;

        if (O == "dec") {
            long long X;
            std::cin >> X;
            if (X == 0) {
                std::cout << 0;
            } else {
                decimalToBinary(X);
            }
            std::cout << "\n";
        } else if (O == "bin") {
            std::string X;
            std::cin >> X;
            std::cout << binaryToDecimal(X) << "\n";
        } else {
            std::string trash;
            std::cin >> trash;
            std::cout << "comando invalido.\n";
        }
    }

    return 0;
}
