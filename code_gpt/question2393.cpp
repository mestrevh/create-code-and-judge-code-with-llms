/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

std::string bigIntMul(const std::string &a, int b) {
    std::vector<int> result;
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        int prod = (a[i] - '0') * b + carry;
        result.push_back(prod % 10);
        carry = prod / 10;
    }
    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
    std::reverse(result.begin(), result.end());
    std::string res;
    for (int num : result) res += (num + '0');
    return res;
}

std::string calcInvites(int n) {
    std::string invites = "1";
    for (int i = 0; i < n; ++i) {
        invites = bigIntMul(invites, 2);
    }
    return invites;
}

int main() {
    int n;
    std::cin >> n;
    std::string result = calcInvites(n);
    for (size_t i = 0; i < result.size(); i += 50) {
        std::cout << result.substr(i, 50) << std::endl;
    }
    return 0;
}
