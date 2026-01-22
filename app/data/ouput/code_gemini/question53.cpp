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

    std::vector<int> answers(16);
    double sum = 0.0;
    long long n = 0;
    int k_target = 1;

    while (k_target <= 15) {
        n++;
        sum += 1.0 / n;
        if (sum > k_target) {
            answers[k_target] = n;
            k_target++;
        }
    }

    int k;
    while (std::cin >> k && k != -1) {
        std::cout << answers[k] << '\n';
    }

    return 0;
}
