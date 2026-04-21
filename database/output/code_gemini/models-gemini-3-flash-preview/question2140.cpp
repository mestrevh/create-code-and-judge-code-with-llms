/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string s;
    if (std::cin >> s) {
        if (!s.empty()) {
            s.pop_back();
            std::cout << s << " " << s << "ndo" << std::endl;
        }
    }
    
    return 0;
}