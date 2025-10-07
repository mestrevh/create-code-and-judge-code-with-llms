/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> pares, impares;

    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        if (num % 2 == 0) {
            pares.push_back(num);
        } else {
            impares.push_back(num);
        }
    }

    std::sort(pares.begin(), pares.end());
    std::sort(impares.begin(), impares.end(), std::greater<int>());

    for (int num : pares) {
        std::cout << num << std::endl;
    }
    for (int num : impares) {
        std::cout << num << std::endl;
    }

    return 0;
}
