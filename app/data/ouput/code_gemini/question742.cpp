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
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    std::cout << s2 << " " << s1 << std::endl;
    return 0;
}
