/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    
    int kyaraWins = 0, viniciusWins = 0;
    
    for (int i = 0; i < N; ++i) {
        std::string kyara, vinicius;
        std::getline(std::cin, kyara);
        std::getline(std::cin, vinicius);
        
        std::transform(kyara.begin(), kyara.end(), kyara.begin(), ::tolower);
        std::transform(vinicius.begin(), vinicius.end(), vinicius.begin(), ::tolower);
        
        if ((kyara != "pedra" && kyara != "papel" && kyara != "tesoura") ||
            (vinicius != "pedra" && vinicius != "papel" && vinicius != "tesoura")) {
            continue;
        }
        
        if (kyara == vinicius) {
            continue;
        } else if ((kyara == "pedra" && vinicius == "tesoura") ||
                   (kyara == "papel" && vinicius == "pedra") ||
                   (kyara == "tesoura" && vinicius == "papel")) {
            kyaraWins++;
        } else {
            viniciusWins++;
        }
    }
    
    if (kyaraWins > viniciusWins) {
        std::cout << "VINICIUS VAI LAVAR A LOUÇA!" << std::endl;
    } else if (viniciusWins > kyaraWins) {
        std::cout << "KYARA VAI LAVAR A LOUÇA!" << std::endl;
    } else {
        std::cout << "OS DOIS VÃO LAVAR A LOUÇA JUNTOS!" << std::endl;
    }
    
    return 0;
}
