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

    std::vector<long long> factorial(16);
    factorial[0] = 1;
    for (int i = 1; i <= 15; ++i) {
        factorial[i] = factorial[i - 1] * i;
    }

    std::string s;
    while (std::cin >> s && s != "0") {
        std::cout << factorial[s.length()] << std::endl;
    }

    return 0;
}
