/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int num;
    while (std::cin >> num && num != 0) {
        std::string str = std::to_string(num);
        std::reverse(str.begin(), str.end());
        std::vector<std::string> result;

        bool leadingZero = true;
        for (char c : str) {
            if (c == '0' && leadingZero) continue;
            leadingZero = false;
            result.push_back("[" + std::string(1, c) + "]");
        }

        if (result.empty()) result.push_back("[0]");
        for (const std::string& s : result) std::cout << s;
        std::cout << std::endl;
    }
    return 0;
}
