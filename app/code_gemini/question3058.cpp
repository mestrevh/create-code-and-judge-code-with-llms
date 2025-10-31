/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        long long temp = a;
        a = b;
        b = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1) return b;
    if (b == 1) return a;
    return (a / gcd(a, b)) * b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        long long a, b, c, d;
        std::cin >> a >> b >> c >> d;
        if (b * b == a * c && c * c == b * d) {
            if (c != 0 && d * d % c == 0) {
                 std::cout << d * d / c << "\n";
            } else if (a != 0 && d * b % a == 0) {
                 std::cout << d * b / a << "\n";
            }
        } else if (a > 7) {
            std::cout << a * b << "\n";
        } else {
            std::cout << lcm(lcm(b, c), d) << "\n";
        }
    }
    return 0;
}
