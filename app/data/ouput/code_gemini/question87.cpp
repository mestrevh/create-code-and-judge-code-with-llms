/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    while (std::cin >> n >> m && (n != 0 || m != 0)) {
        std::unordered_map<std::string, int> dna_counts;
        for (int i = 0; i < n; ++i) {
            std::string dna;
            std::cin >> dna;
            dna_counts[dna]++;
        }

        std::vector<int> results(n + 1, 0);
        for (const auto& pair : dna_counts) {
            if (pair.second <= n) {
                results[pair.second]++;
            }
        }

        for (int i = 1; i <= n; ++i) {
            std::cout << results[i] << "\n";
        }
    }

    return 0;
}
