/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    if (std::getline(std::cin, line)) {
        long long count = 0;
        for (char c : line) {
            if (c == 'a' || c == 'A') {
                count++;
            }
        }
        std::cout << count << "\n";
    }

    return 0;
}