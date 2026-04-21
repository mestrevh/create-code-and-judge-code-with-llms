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
        bool valid = (s.length() == 4);
        if (valid) {
            for (char c : s) {
                if (c < '1' || c > '9') {
                    valid = false;
                    break;
                }
            }
        }
        
        if (valid) {
            std::cout << "Pode" << std::endl;
        } else {
            std::cout << "Nao pode" << std::endl;
        }
    }

    return 0;
}