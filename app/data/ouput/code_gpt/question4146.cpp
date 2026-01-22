/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>

int main() {
    long long N, A, B;
    std::cin >> N >> A >> B;
    
    auto sum = (N * (N + 1)) / 2;
    sum -= (A * (N / A) * (N / A + 1)) / 2;
    sum -= (B * (N / B) * (N / B + 1)) / 2;
    sum += (A * B * (N / (A * B)) * (N / (A * B) + 1)) / 2;

    std::cout << sum << std::endl;
    std::cout << (sum % 2 == 0 ? "Lá ele!!!" : "Opa xupenio AULAS...") << std::endl;

    return 0;
}
