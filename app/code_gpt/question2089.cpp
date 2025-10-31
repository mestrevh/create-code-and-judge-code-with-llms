/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_set>

int squareSum(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

int main() {
    int N;
    std::cin >> N;
    std::unordered_set<int> seen;

    while (N != 1 && seen.find(N) == seen.end()) {
        seen.insert(N);
        N = squareSum(N);
    }

    std::cout << (N == 1 ? "S" : "N") << std::endl;
    return 0;
}
