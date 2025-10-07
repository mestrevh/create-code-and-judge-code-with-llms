/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(int n) {
    std::string s = std::to_string(n);
    return std::equal(s.begin(), s.end(), s.rbegin());
}

int reverseNumber(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int number;
        std::cin >> number;
        int iterations = 0;
        while (!isPalindrome(number) && iterations < 1000) {
            int reversed = reverseNumber(number);
            number += reversed;
            iterations++;
        }
        std::cout << iterations << " " << number << std::endl;
    }
    return 0;
}
