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

    int N;
    std::cin >> N;

    while (N--) {
        int L;
        std::cin >> L;
        int total_hash = 0;
        for (int i = 0; i < L; ++i) {
            std::string s;
            std::cin >> s;
            for (size_t j = 0; j < s.length(); ++j) {
                total_hash += (s[j] - 'A') + i + j;
            }
        }
        std::cout << total_hash << std::endl;
    }

    return 0;
}
