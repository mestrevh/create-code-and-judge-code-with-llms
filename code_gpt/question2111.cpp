/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    std::vector<double> nums;
    double num;
    double sum = 0;
    int count = 0;

    while (std::cin >> num) {
        nums.push_back(num);
    }

    for (double n : nums) {
        if (n > 0 && static_cast<int>(n) % 2 == 0) {
            sum += n;
            count++;
        }
    }

    if (count > 0) {
        std::cout << std::fixed << std::setprecision(2) << sum / count << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}
