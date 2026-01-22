/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    int k = 0;
    if (n > 0) {
        k = static_cast<int>(floor(log(n) / log(3)));
    }
    
    long long ambrosio_number = 1;
    for (int i = 2; i <= k; ++i) {
        ambrosio_number *= i;
    }

    std::cout << ambrosio_number << std::endl;

    return 0;
}
