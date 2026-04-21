/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long calculate_gcd(long long a, long long b) {
    while (b) {
        a %= b;
        long long temp = a;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long current_number;
    long long result_gcd = 0;

    while (std::cin >> current_number && current_number > 0) {
        if (result_gcd == 0) {
            result_gcd = current_number;
        } else {
            result_gcd = calculate_gcd(result_gcd, current_number);
        }
    }

    if (result_gcd > 0) {
        std::cout << result_gcd << "\n";
    }

    return 0;
}