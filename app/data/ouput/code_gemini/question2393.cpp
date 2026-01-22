/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

const int BASE = 1000000000;

std::vector<int> multiplyByInt(const std::vector<int>& num, int factor) {
    if (factor == 0) {
        return {0};
    }
    std::vector<int> result;
    result.reserve(num.size() + 2);
    long long carry = 0;
    for (int digit : num) {
        long long product = static_cast<long long>(digit) * factor + carry;
        result.push_back(product % BASE);
        carry = product / BASE;
    }
    while (carry > 0) {
        result.push_back(carry % BASE);
        carry /= BASE;
    }
    return result;
}

std::vector<int> multiply(const std::vector<int>& num1, const std::vector<int>& num2) {
    std::vector<int> result(num1.size() + num2.size(), 0);
    for (size_t i = 0; i < num1.size(); ++i) {
        long long carry = 0;
        for (size_t j = 0; j < num2.size() || carry > 0; ++j) {
            long long current = result[i + j] + carry;
            if (j < num2.size()) {
                current += static_cast<long long>(num1[i]) * num2[j];
            }
            result[i + j] = current % BASE;
            carry = current / BASE;
        }
    }
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}

std::vector<int> powerOfTwo(int n) {
    if (n == 0) {
        return {1};
    }
    if (n == 1) {
        return {2};
    }
    
    std::vector<int> half = powerOfTwo(n / 2);
    std::vector<int> result = multiply(half, half);
    
    if (n % 2 != 0) {
        result = multiplyByInt(result, 2);
    }
    
    return result;
}

void printBigNum(const std::vector<int>& num) {
    if (num.empty() || (num.size() == 1 && num[0] == 0)) {
        std::cout << "0\n";
        return;
    }
    
    std::stringstream ss;
    ss << num.back();
    
    for (int i = static_cast<int>(num.size()) - 2; i >= 0; --i) {
        ss << std::setw(9) << std::setfill('0') << num[i];
    }
    
    std::string s = ss.str();
    
    for (size_t i = 0; i < s.length(); i += 50) {
        std::cout << s.substr(i, 50) << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> result = powerOfTwo(n);
    printBigNum(result);

    return 0;
}
