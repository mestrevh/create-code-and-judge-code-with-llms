/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

void print_128(__int128_t n) {
    if (n == 0) {
        std::cout << "0";
        return;
    }
    std::string s;
    while (n > 0) {
        s += (n % 10) + '0';
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    std::cout << s;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n0_ll, n_ll;
    std::cin >> n0_ll >> n_ll;

    __int128_t n0 = n0_ll;
    __int128_t n = n_ll;

    __int128_t num_terms = n - n0 + 1;
    __int128_t sum_first_last = n0 + n;
    
    __int128_t total_sum = num_terms * sum_first_last / 2;

    print_128(total_sum);
    std::cout << std::endl;

    return 0;
}
