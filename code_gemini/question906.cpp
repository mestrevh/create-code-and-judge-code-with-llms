/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const int N = 10;
    std::vector<double> nums(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }

    std::cout << std::fixed << std::setprecision(1);

    for (int i = N - 1; i >= 0; --i) {
        std::cout << nums[i] << std::endl;
    }

    return 0;
}
