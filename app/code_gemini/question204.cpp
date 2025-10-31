/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long sides[3];
    std::cin >> sides[0] >> sides[1] >> sides[2];
    std::sort(sides, sides + 3);
    long long a = sides[0];
    long long b = sides[1];
    long long c = sides[2];
    if (a + b <= c) {
        std::cout << "n" << std::endl;
    } else {
        long long a_sq = a * a;
        long long b_sq = b * b;
        long long c_sq = c * c;
        if (a_sq + b_sq > c_sq) {
            std::cout << "a" << std::endl;
        } else if (a_sq + b_sq == c_sq) {
            std::cout << "r" << std::endl;
        } else {
            std::cout << "o" << std::endl;
        }
    }
    return 0;
}
