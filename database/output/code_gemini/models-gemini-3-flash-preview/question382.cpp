/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long sum = 0;
    int count = 0;
    int value;

    while (std::cin >> value && value != 0) {
        sum += value;
        count++;
    }

    if (count > 0) {
        // We use integer multiplication to avoid floating point precision issues
        // avg < 110  => sum / count < 110  => sum < 110 * count
        // avg >= 200 => sum / count >= 200 => sum >= 200 * count
        if (sum < 110LL * count) {
            std::cout << "Glicose Normal" << std::endl;
        } else if (sum >= 200LL * count) {
            std::cout << "Glicose Muito Alta" << std::endl;
        } else {
            std::cout << "Glicose Alterada" << std::endl;
        }
    }

    return 0;
}