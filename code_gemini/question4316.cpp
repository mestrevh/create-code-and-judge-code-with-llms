/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::string s;
    while (std::cin >> n >> s) {
        std::reverse(s.begin(), s.end());
        try {
            long long reversed_num = std::stoll(s);
            std::cout << reversed_num << std::endl;
        } catch (const std::out_of_range& oor) {
            std::cout << s << std::endl;
        }
    }
    return 0;
}
