/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    if (std::getline(std::cin, s)) {
        // Handle potential trailing CR from Windows-style line endings
        if (!s.empty() && s.back() == '\r') {
            s.pop_back();
        }
        
        for (char &c : s) {
            c = (char)std::toupper((unsigned char)c);
        }
        
        std::cout << s << "\n";
    }

    return 0;
}