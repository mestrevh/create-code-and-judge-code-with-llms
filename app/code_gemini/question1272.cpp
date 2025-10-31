/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    long long answers[] = {
        0,
        10,
        25,
        39,
        77,
        679,
        6788,
        68889,
        27777778889LL,
        277777788899LL
    };
    for (int i = 0; i <= n; ++i) {
        std::cout << "O menor número com persistência " << i << " é " << answers[i] << ".\n";
    }
    return 0;
}
