/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::cin >> s;
    std::string result;
    result.reserve(s.length());
    for (char c : s) {
        result.push_back(c);
        if (result.length() >= 3) {
            if (result[result.length() - 3] == 'A' &&
                result[result.length() - 2] == 'B' &&
                result[result.length() - 1] == 'C') {
                result.resize(result.length() - 3);
            }
        }
    }
    if (result.empty()) {
        std::cout << "string vazia\n";
    } else {
        std::cout << result << "\n";
    }
    return 0;
}
