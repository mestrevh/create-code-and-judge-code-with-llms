/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

long long power(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

bool isArmstrong(int n) {
    if (n < 0) {
        return false;
    }

    int original_n = n;
    int num_digits = 0;
    
    if (n == 0) {
        num_digits = 1;
    } else {
        int temp = n;
        while (temp > 0) {
            temp /= 10;
            num_digits++;
        }
    }

    long long sum = 0;
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += power(digit, num_digits);
        if (sum > original_n) {
            return false;
        }
        temp /= 10;
    }

    return sum == original_n;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b;
    std::cin >> a >> b;

    std::vector<int> armstrongs;
    for (int i = a; i <= b; ++i) {
        if (isArmstrong(i)) {
            armstrongs.push_back(i);
        }
    }

    bool first = true;
    for (int num : armstrongs) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << num;
        first = false;
    }
    std::cout << "\n";

    std::cout << armstrongs.size() << " numeros de Armstrong\n";

    return 0;
}
