/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::cin >> s;
    int total = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            bool accompanied = false;
            if (i > 0 && s[i - 1] == 'i') {
                accompanied = true;
            }
            if (i < n - 1 && s[i + 1] == 'i') {
                accompanied = true;
            }
            if (accompanied) {
                total += 2;
            } else {
                total += 1;
            }
        }
    }
    std::cout << total << std::endl;
    return 0;
}
