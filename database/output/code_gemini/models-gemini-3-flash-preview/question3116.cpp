/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <cstdlib>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, l, p, h;
    std::cin >> a >> l >> p >> h;

    long long diamonds_a = a * h;
    long long diamonds_l = l * h;
    long long diamonds_p = p * h;

    long long max_al = (diamonds_a + diamonds_l + std::abs(diamonds_a - diamonds_l)) / 2;
    long long max_final = (max_al + diamonds_p + std::abs(max_al - diamonds_p)) / 2;

    std::cout << max_final << std::endl;

    return 0;
}