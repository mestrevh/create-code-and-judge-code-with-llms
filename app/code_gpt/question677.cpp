/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int T;
    std::cin >> T;
    std::cin.ignore();
    while (T--) {
        std::string S;
        std::getline(std::cin, S);
        int N;
        std::cin >> N;
        std::cin.ignore();
        
        std::unordered_map<char, std::string> shortcuts;
        for (int i = 0; i < N; i++) {
            char C;
            std::string A;
            std::cin >> C;
            std::getline(std::cin, A);
            shortcuts[C] = A.substr(1); // remove espaço antes da string
        }
        
        std::string result;
        for (size_t i = 0; i < S.size(); i++) {
            if (S[i] == '*') {
                if (i + 1 < S.size() && shortcuts.find(S[i + 1]) != shortcuts.end()) {
                    result += shortcuts[S[i + 1]];
                    i++;
                } else {
                    result += '*';
                }
            } else {
                result += S[i];
            }
        }
        std::cout << result << '\n';
    }
    return 0;
}
