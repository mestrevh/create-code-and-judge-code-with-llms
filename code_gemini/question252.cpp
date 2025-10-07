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
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int count = 0;
    size_t pos = s1.find(s2, 0);
    while (pos != std::string::npos) {
        count++;
        pos = s1.find(s2, pos + 1);
    }
    std::cout << count << std::endl;
    return 0;
}
