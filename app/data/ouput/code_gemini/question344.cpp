/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
#include <algorithm>

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    size_t dot_pos = s.find('.');

    long long numerator;
    long long denominator = 1;

    if (dot_pos == std::string::npos) {
        numerator = std::stoll(s);
    } else {
        int decimal_places = s.length() - dot_pos - 1;
        for (int i = 0; i < decimal_places; ++i) {
            denominator *= 10;
        }

        s.erase(dot_pos, 1);
        numerator = std::stoll(s);
    }

    long long common_divisor = gcd(std::abs(numerator), std::abs(denominator));

    numerator /= common_divisor;
    denominator /= common_divisor;

    std::cout << numerator << "/" << denominator << std::endl;

    return 0;
}
