/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

bool dividesAll(const std::vector<int>& ns, int n) {
    for (int num : ns) {
        if (num % n != 0) return false;
    }
    return true;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    std::vector<int> numbers;
    int num;
    
    while (std::cin >> num && num > 0) {
        numbers.push_back(num);
    }

    int result = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        result = gcd(result, numbers[i]);
    }

    std::cout << result << std::endl;
    return 0;
}
