/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void backtrack(std::string& current, int ones, int N, int pos, std::vector<std::string>& results) {
    if (current.size() == N) {
        if (ones == 0) results.push_back(current);
        return;
    }
    
    // Choose 0
    current.push_back('0');
    backtrack(current, ones, N, pos + 1, results);
    current.pop_back();
    
    // Choose 1 if we still have space
    if (ones > 0) {
        current.push_back('1');
        backtrack(current, ones - 1, N, pos + 1, results);
        current.pop_back();
    }
}

int main() {
    int T;
    std::cin >> T;
    std::cin.ignore();
    std::cin.ignore(); // Ignorar a linha em branco

    while (T--) {
        int N, H;
        std::cin >> N >> H;
        std::cin.ignore();
        
        std::vector<std::string> results;
        std::string current;

        backtrack(current, H, N, 0, results);
        
        std::sort(results.begin(), results.end());

        for (const auto& str : results) {
            std::cout << str << std::endl;
        }
        
        if (T > 0) std::cout << std::endl; // Linha em branco entre os casos de teste
    }
    
    return 0;
}
