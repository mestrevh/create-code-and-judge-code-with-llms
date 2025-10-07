/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int ano;
    std::string era;

    std::cin >> ano >> era;

    if (era == "aC") {
        if (ano > 4000) {
            std::cout << "PRE-HISTORIA\n";
        } else {
            std::cout << "ANTIGUIDADE\n";
        }
    } else { // era == "dC"
        if (ano < 477) {
            std::cout << "ANTIGUIDADE\n";
        } else if (ano < 1454) {
            std::cout << "IDADE MEDIA\n";
        } else if (ano < 1790) {
            std::cout << "IDADE MODERNA\n";
        } else {
            std::cout << "IDADE CONTEMPORANEA\n";
        }
    }

    return 0;
}
