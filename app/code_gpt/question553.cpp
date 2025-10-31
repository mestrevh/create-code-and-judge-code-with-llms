/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

std::string soma(const std::string &a, const std::string &b) {
    std::string res;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res += (sum % 10) + '0';
        carry = sum / 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

std::string multiplicacao(const std::string &a, const std::string &b) {
    if (a == "0" || b == "0") return "0";
    
    std::string res(a.size() + b.size(), '0');
    
    for (int i = a.size() - 1; i >= 0; --i) {
        for (int j = b.size() - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + (res[i + j + 1] - '0');
            res[i + j + 1] = (sum % 10) + '0';
            res[i + j] += sum / 10;
        }
    }
    size_t start = res.find_first_not_of('0');
    return start == std::string::npos ? "0" : res.substr(start);
}

int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::cout << soma(a, b) << std::endl;
    std::cout << multiplicacao(a, b) << std::endl;
    return 0;
}
