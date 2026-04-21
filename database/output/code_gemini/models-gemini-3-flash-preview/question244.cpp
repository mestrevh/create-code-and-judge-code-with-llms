/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    char target;

    if (std::getline(std::cin, s)) {
        // Remove possible carriage return at the end of the line in certain environments
        if (!s.empty() && s.back() == '\r') {
            s.pop_back();
        }

        if (std::cin >> target) {
            int occurrences = 0;
            for (char c : s) {
                if (c == target) {
                    occurrences++;
                }
            }
            std::cout << occurrences << "\n";
        }
    }

    return 0;
}