/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int total_quebrados = 0;
    for (int i = 0; i < n; ++i) {
        int l, c;
        std::cin >> l >> c;
        if (l > c) {
            total_quebrados += c;
        }
    }
    std::cout << total_quebrados << std::endl;
    return 0;
}
