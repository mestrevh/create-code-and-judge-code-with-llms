/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string passeio;
    int cinema_count = 0, boliche_count = 0;
    
    for (int i = 0; i < 6; ++i) {
        std::getline(std::cin, passeio);
        std::transform(passeio.begin(), passeio.end(), passeio.begin(), ::tolower);
        if (passeio == "cinema") {
            cinema_count++;
        } else if (passeio == "boliche") {
            boliche_count++;
        }
    }
    
    if (cinema_count >= boliche_count) {
        std::cout << "CINEMA" << std::endl;
    } else {
        std::cout << "BOLICHE" << std::endl;
    }
    
    return 0;
}
