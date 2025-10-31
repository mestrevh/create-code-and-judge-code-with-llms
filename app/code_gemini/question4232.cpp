/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

bool divides_all(const std::vector<int>& ns, int n) {
    if (n <= 0) return false;
    for (int x : ns) {
        if (x % n != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int result_gcd;
    if (!(std::cin >> result_gcd) || result_gcd <= 0) {
        return 0;
    }

    int current_num;
    while (std::cin >> current_num && current_num > 0) {
        result_gcd = std::gcd(result_gcd, current_num);
    }

    std::cout << result_gcd << '\n';

    return 0;
}
