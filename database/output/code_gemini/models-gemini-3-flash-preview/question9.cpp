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

    int n;
    while (std::cin >> n && n != 0) {
        std::string s(n, ' ');
        // Skip leading whitespace to reach the start of the character sequence
        std::cin >> std::ws;
        // Read exactly n characters into the string
        std::cin.read(&s[0], n);
        // Reverse the string in-place
        std::reverse(s.begin(), s.end());
        // Output the reversed string followed by a newline
        std::cout << s << "\n";
    }

    return 0;
}