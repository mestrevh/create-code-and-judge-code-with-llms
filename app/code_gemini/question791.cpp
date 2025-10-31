/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <numeric>

long long calculateSuperDigit(long long n) {
    if (n < 10) {
        return n;
    }
    long long sum = 0;
    long long temp = n;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    return calculateSuperDigit(sum);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string n;
    long long k;
    std::cin >> n >> k;
    
    long long initial_sum = 0;
    for (char c : n) {
        initial_sum += (c - '0');
    }
    
    long long p = initial_sum * k;
    
    std::cout << calculateSuperDigit(p) << std::endl;
    
    return 0;
}
