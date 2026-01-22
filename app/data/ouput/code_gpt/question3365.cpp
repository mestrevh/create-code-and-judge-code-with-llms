/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main() {
    std::string D, S;
    std::cin >> D >> S;
    int N;
    std::cin >> N;
    
    std::unordered_map<char, char> mapping;
    for (size_t i = 0; i < D.size(); ++i) {
        mapping[D[i]] = S[i];
    }

    std::vector<std::string> results(N);
    for (int i = 0; i < N; ++i) {
        std::string test;
        std::cin >> test;
        std::string decoded;
        for (char c : test) {
            decoded += mapping.count(c) ? mapping[c] : c;
        }
        results[i] = decoded;
    }

    for (const auto& res : results) {
        std::cout << res << std::endl;
    }

    return 0;
}
