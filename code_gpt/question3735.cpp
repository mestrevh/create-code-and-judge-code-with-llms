/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    int total = 0;
    
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a') {
            total++;
            if (i > 0 && (s[i - 1] == 'i' || s[i - 1] == 'a')) total++;
            if (i < s.size() - 1 && (s[i + 1] == 'i' || s[i + 1] == 'a')) total++;
        }
    }
    std::cout << total << std::endl;
    return 0;
}
