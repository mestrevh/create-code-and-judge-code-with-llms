/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool isPalindrome(const std::string& s) {
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

std::string addStrings(const std::string& num1, const std::string& num2) {
    std::string result = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result += std::to_string(sum % 10);
        carry = sum / 10;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

void solve() {
    std::string p;
    std::cin >> p;

    int iterations = 0;
    while (!isPalindrome(p)) {
        iterations++;
        std::string reversed_p = p;
        std::reverse(reversed_p.begin(), reversed_p.end());
        p = addStrings(p, reversed_p);
    }

    std::cout << iterations << " " << p << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    while (n--) {
        solve();
    }

    return 0;
}
