/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long read_and_reverse() {
    int n;
    std::cin >> n;

    if (n == 0) {
        long long val;
        std::cin >> val;
        return val;
    }

    long long val;
    std::cin >> val;
    return val + 10 * read_and_reverse();
}

long long build_number(int n) {
    if (n == 0) {
        return 0;
    }
    long long digit;
    std::cin >> digit;
    return digit + 10 * build_number(n - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int p;
    std::cin >> p;

    long long total_sum = 0;
    for (int i = 0; i < p; ++i) {
        int n;
        std::cin >> n;
        total_sum += build_number(n);
    }

    std::cout << total_sum << std::endl;

    return 0;
}
