/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstring>
#include <iomanip>

int main() {
    char frase[101];
    std::cin.getline(frase, 101);
    
    int count[5] = {0}; // a, e, i, o, u
    int total = 0;
    
    for (int i = 0; frase[i] != '\0'; ++i) {
        char ch = tolower(frase[i]);
        if (ch >= 'a' && ch <= 'z') {
            total++;
            switch (ch) {
                case 'a': count[0]++; break;
                case 'e': count[1]++; break;
                case 'i': count[2]++; break;
                case 'o': count[3]++; break;
                case 'u': count[4]++; break;
            }
        }
    }
    
    for (int i = 0; i < 5; ++i) {
        char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
        std::cout << vogais[i] << " " << count[i] << std::endl;
    }
    
    double porcentagem = (total > 0) ? (static_cast<double>(count[0] + count[1] + count[2] + count[3] + count[4]) / total) * 100 : 0;
    std::cout << std::fixed << std::setprecision(2) << porcentagem << "%" << std::endl;
    
    return 0;
}
