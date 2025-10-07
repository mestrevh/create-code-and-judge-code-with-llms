/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int n, m;
    while (std::cin >> n >> m, n || m) {
        std::unordered_map<std::string, int> dnaCount;
        for (int i = 0; i < n; ++i) {
            std::string dna;
            std::cin >> dna;
            dnaCount[dna]++;
        }
        
        std::vector<int> copies(n + 1, 0);
        for (const auto& pair : dnaCount) {
            copies[pair.second]++;
        }
        
        for (int i = 0; i <= n; ++i) {
            std::cout << copies[i] << std::endl;
        }
    }
    return 0;
}
