/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, a, b;
    std::cin >> n;
    std::cin >> a >> b;

    long long total_sum = n * (n + 1) / 2;

    long long m_a = n / a;
    long long sum_a = a * m_a * (m_a + 1) / 2;

    long long final_sum;

    if (a == b) {
        final_sum = total_sum - sum_a;
    } else {
        long long m_b = n / b;
        long long sum_b = b * m_b * (m_b + 1) / 2;

        long long c = a * b;
        long long sum_ab = 0;
        if (c / a == b && c > 0) {
            long long m_ab = n / c;
            sum_ab = c * m_ab * (m_ab + 1) / 2;
        }
        
        final_sum = total_sum - sum_a - sum_b + sum_ab;
    }

    std::cout << final_sum << "\n";

    if (final_sum % 2 == 0) {
        std::cout << "Lá ele!!!\n";
    } else {
        std::cout << "Opa xupenio AULAS...\n";
    }

    return 0;
}
