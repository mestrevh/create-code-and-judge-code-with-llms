/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    std::string input;
    std::cin >> input;
    std::vector<std::string> results;

    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            std::string temp = input;
            temp[1] = '0' + i;
            temp[2] = '0' + j;
            int num = (i * 10) + j;
            int previous = num - 1, next = num + 1;

            if (is_prime(num / previous) && is_prime(num / next)) {
                results.push_back(temp);
            }
        }
    }

    if (results.empty()) {
        std::cout << "Marquinhos esta louco!\n";
    } else {
        std::sort(results.begin(), results.end());
        for (const auto& result : results) {
            std::cout << result << "\n";
        }
    }
    return 0;
}
