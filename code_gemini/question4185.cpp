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

    std::vector<int> pares;
    std::vector<int> impares;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        if (num % 2 == 0) {
            pares.push_back(num);
        } else {
            impares.push_back(num);
        }
    }

    for (size_t i = 0; i < pares.size(); ++i) {
        std::cout << "pares[" << i << "] = " << pares[i] << "\n";
    }

    for (size_t i = 0; i < impares.size(); ++i) {
        std::cout << "impares[" << i << "] = " << impares[i] << "\n";
    }

    return 0;
}
