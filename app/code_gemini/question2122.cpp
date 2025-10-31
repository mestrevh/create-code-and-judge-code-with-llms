/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>

std::map<int, long long> memo;

long long monk_function(int x) {
    if (x == 0) return 10;
    if (x == 1) return 11;
    if (x == 2) return 27;

    if (memo.count(x)) {
        return memo[x];
    }

    long long result = monk_function(x - 2) - monk_function(x - 3);
    memo[x] = result;
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    while (std::cin >> x) {
        std::cout << monk_function(x) << std::endl;
    }

    return 0;
}
