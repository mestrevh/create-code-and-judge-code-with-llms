/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    long long total_prefix_sum = 0;
    int num_trailing_zeros = -1;
    const int prefix_length = 5;

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;

        long long current_prefix_val;
        int num_part_length;

        if (s[0] == '-') {
            current_prefix_val = -std::stoll(s.substr(1, prefix_length));
            num_part_length = s.length() - 1;
        } else {
            current_prefix_val = std::stoll(s.substr(0, prefix_length));
            num_part_length = s.length();
        }
        
        total_prefix_sum += current_prefix_val;

        if (num_trailing_zeros == -1) {
            num_trailing_zeros = num_part_length - prefix_length;
        }
    }
    
    if (total_prefix_sum == 0) {
        std::cout << "0\n";
    } else {
        std::cout << total_prefix_sum;
        if (num_trailing_zeros > 0) {
            std::string zeros(num_trailing_zeros, '0');
            std::cout << zeros;
        }
        std::cout << '\n';
    }

    return 0;
}
