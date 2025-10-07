/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    long long N;
    std::cin >> N;
    long long sum = 0;
    for (long long i = 0; i < N; ++i) {
        std::string num;
        std::cin >> num;
        sum += std::stoll(num);
    }
    std::cout << sum << std::endl;
    return 0;
}
