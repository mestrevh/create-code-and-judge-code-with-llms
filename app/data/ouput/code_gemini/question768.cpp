/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n1;
    std::cin >> n1;
    std::vector<int> num1(n1);
    for (int i = 0; i < n1; ++i) {
        std::cin >> num1[i];
    }

    int n2;
    std::cin >> n2;
    std::vector<int> num2(n2);
    for (int i = 0; i < n2; ++i) {
        std::cin >> num2[i];
    }

    std::vector<int> result;
    int carry = 0;
    int i = n1 - 1;
    int j = n2 - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int d1 = (i >= 0) ? num1[i] : 0;
        int d2 = (j >= 0) ? num2[j] : 0;

        int current_sum = d1 + d2 + carry;
        result.push_back(current_sum % 10);
        carry = current_sum / 10;

        i--;
        j--;
    }

    for (int k = result.size() - 1; k >= 0; --k) {
        std::cout << result[k];
    }
    std::cout << std::endl;

    return 0;
}
