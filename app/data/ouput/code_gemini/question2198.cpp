/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long m;
    std::cin >> m;

    long long original_m = m;
    long long temp_m_for_count = m;
    int n = 0;

    if (temp_m_for_count == 0) {
        n = 1;
    } else {
        while (temp_m_for_count > 0) {
            temp_m_for_count /= 10;
            n++;
        }
    }

    long long armstrong_sum = 0;
    long long temp_m_for_sum = m;

    while (temp_m_for_sum > 0) {
        int digit = temp_m_for_sum % 10;
        armstrong_sum += round(pow(digit, n));
        temp_m_for_sum /= 10;
    }

    if (armstrong_sum == original_m) {
        std::cout << "Armstrong" << std::endl;
    } else {
        std::cout << "soma: " << armstrong_sum << std::endl;
    }

    return 0;
}
