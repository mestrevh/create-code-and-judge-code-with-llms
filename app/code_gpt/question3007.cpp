/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    long long A, B;
    std::cin >> A >> B;

    long long gcd = std::__gcd(A, B);
    int count = 0;

    for (long long i = 1; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            count++;
            if (i != gcd / i) count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
