/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string add(std::string num1, std::string num2) {
    std::string result = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i--] - '0';
        }
        if (j >= 0) {
            sum += num2[j--] - '0';
        }
        result += std::to_string(sum % 10);
        carry = sum / 10;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::string multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }

    int n1 = num1.length();
    int n2 = num2.length();
    std::vector<int> res(n1 + n2, 0);

    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = mul + res[p2];

            res[p1] += sum / 10;
            res[p2] = sum % 10;
        }
    }

    std::string result_str = "";
    bool leading_zero = true;
    for (int p : res) {
        if (p == 0 && leading_zero) {
            continue;
        }
        leading_zero = false;
        result_str += std::to_string(p);
    }
    
    return result_str.empty() ? "0" : result_str;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string a, b;
    std::cin >> a >> b;

    std::cout << add(a, b) << std::endl;
    std::cout << multiply(a, b) << std::endl;

    return 0;
}
