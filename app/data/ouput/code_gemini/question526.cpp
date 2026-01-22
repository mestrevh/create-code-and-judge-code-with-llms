/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());

    std::string result = "";
    int carry = 0;

    size_t n1 = s1.length();
    size_t n2 = s2.length();
    size_t max_len = std::max(n1, n2);

    for (size_t i = 0; i < max_len; ++i) {
        int digit1 = (i < n1) ? (s1[i] - '0') : 0;
        int digit2 = (i < n2) ? (s2[i] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    if (carry > 0) {
        result.push_back(carry + '0');
    }

    std::reverse(result.begin(), result.end());

    std::cout << result << "\n";

    return 0;
}
