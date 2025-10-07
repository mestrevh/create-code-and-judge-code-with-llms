/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N, X;
    std::cin >> N;
    std::string s;
    std::cin >> s;
    std::cin >> X;

    for (char &c : s) {
        c = (c - 'a' + X) % 26 + 'a';
    }

    std::cout << s << std::endl;
    return 0;
}
