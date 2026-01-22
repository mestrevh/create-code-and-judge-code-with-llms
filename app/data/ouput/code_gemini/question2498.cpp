/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string n_str;
    std::cin >> n_str;
    int len = n_str.length();
    int half_len = len / 2;
    int first_half_sum = 0;
    int second_half_sum = 0;
    for (int i = 0; i < half_len; ++i) {
        first_half_sum += n_str[i] - '0';
    }
    for (int i = half_len; i < len; ++i) {
        second_half_sum += n_str[i] - '0';
    }
    if (first_half_sum == second_half_sum) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }
    return 0;
}
