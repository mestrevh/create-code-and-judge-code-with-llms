/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct DnaInfo {
    std::string sequence;
    int inversions;
};

int calculate_inversions(const std::string& s) {
    int count = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        for (size_t j = i + 1; j < s.length(); ++j) {
            if (s[i] > s[j]) {
                count++;
            }
        }
    }
    return count;
}

void solve() {
    int length, count;
    std::cin >> length >> count;
    
    std::vector<DnaInfo> dnas(count);
    
    for (int i = 0; i < count; ++i) {
        std::cin >> dnas[i].sequence;
        dnas[i].inversions = calculate_inversions(dnas[i].sequence);
    }
    
    std::stable_sort(dnas.begin(), dnas.end(), [](const DnaInfo& a, const DnaInfo& b) {
        return a.inversions < b.inversions;
    });
    
    for (int i = 0; i < count; ++i) {
        std::cout << dnas[i].sequence << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int M;
    std::cin >> M;
    
    for (int i = 0; i < M; ++i) {
        if (i > 0) {
            std::cout << std::endl;
        }
        solve();
    }
    
    return 0;
}
