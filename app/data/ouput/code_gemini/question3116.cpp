/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a, l, p, h;
    std::cin >> a >> l >> p >> h;
    long long total_a = a * h;
    long long total_l = l * h;
    long long total_p = p * h;
    long long max_lp = (total_l + total_p + std::abs(total_l - total_p)) / 2;
    long long final_max = (total_a + max_lp + std::abs(total_a - max_lp)) / 2;
    std::cout << final_max << std::endl;
    return 0;
}
