/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") {
        std::cout << "0" << std::endl;
        return;
    }

    int n1 = num1.length();
    int n2 = num2.length();
    std::vector<int> result(n1 + n2, 0);

    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int d1 = num1[i] - '0';
        i_n2 = 0;
        for (int j = n2 - 1; j >= 0; j--) {
            int d2 = num2[j] - '0';
            int sum = d1 * d2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0) {
            result[i_n1 + i_n2] += carry;
        }
        i_n1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0) {
        i--;
    }

    if (i == -1) {
        std::cout << "0" << std::endl;
        return;
    }

    while (i >= 0) {
        std::cout << result[i--];
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str1, str2;
    std::cin >> str1 >> str2;

    multiply(str1, str2);

    return 0;
}
