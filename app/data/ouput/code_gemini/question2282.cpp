/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int count_occurrences(unsigned int n, int x) {
    if (n == 0) {
        return 0;
    }
    
    int last_digit = n % 10;
    int count = (last_digit == x) ? 1 : 0;
    
    return count + count_occurrences(n / 10, x);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    unsigned int n;
    int x;
    std::cin >> n >> x;
    
    if (n == 0 && x == 0) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << count_occurrences(n, x) << std::endl;
    }
    
    return 0;
}
