/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

std::string decrypt(const std::string& s, int pos) {
    if (pos == s.length()) {
        return "";
    }
    
    std::string decrypted_rest = decrypt(s, pos + 1);
    std::string current_pos_str = std::to_string(pos + 1);
    
    if (s[pos] == '*') {
        return "(" + current_pos_str + decrypted_rest + ")";
    } else {
        return current_pos_str + decrypted_rest;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string s;
    std::cin >> s;
    
    std::cout << decrypt(s, 0) << std::endl;
    
    return 0;
}
