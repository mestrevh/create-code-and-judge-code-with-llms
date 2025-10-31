/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);
    std::vector<int> freqA(n + 1, 0);
    std::vector<int> freqB(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        freqA[a[i]]++;
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        freqB[b[i]]++;
    }

    std::cout << "VetOUr:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << (a[i] | b[i]) << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";

    std::cout << "ANDrray:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << (a[i] & b[i]) << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";

    std::cout << "Frequencia em A:\n";
    for (int i = 0; i <= n; ++i) {
        std::cout << freqA[i] << (i == n ? "" : " ");
    }
    std::cout << "\n";

    std::cout << "Frequencia em B:\n";
    for (int i = 0; i <= n; ++i) {
        std::cout << freqB[i] << (i == n ? "" : " ");
    }
    std::cout << "\n";

    return 0;
}
