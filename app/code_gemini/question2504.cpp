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
    std::getline(std::cin, s);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int index;
        char new_char;
        std::cin >> index;
        std::cin >> new_char;
        s[index] = new_char;
    }

    std::cout << s << std::endl;

    return 0;
}
