/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>
#include <vector>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    long long result = nums[0];
    for (int i = 1; i < n; ++i) {
        result = lcm(result, nums[i]);
    }
    std::cout << result << std::endl;
    return 0;
}

