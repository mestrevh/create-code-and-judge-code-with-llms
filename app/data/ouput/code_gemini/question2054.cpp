/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long N, A, B;
    std::cin >> N >> A >> B;

    long long total_sum = N * (N + 1) / 2;

    long long count_a = N / A;
    long long sum_a = A * (count_a * (count_a + 1) / 2);

    long long count_b = N / B;
    long long sum_b = B * (count_b * (count_b + 1) / 2);
    
    long long common_multiple = A * B;
    long long count_ab = N / common_multiple;
    long long sum_ab = common_multiple * (count_ab * (count_ab + 1) / 2);

    long long result = total_sum - sum_a - sum_b + sum_ab;

    std::cout << result << std::endl;

    return 0;
}
