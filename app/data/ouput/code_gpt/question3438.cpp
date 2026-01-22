/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <set>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    
    std::map<std::string, std::set<std::string>> supermercado;
    
    for (int i = 0; i < n; i++) {
        std::string secao;
        std::getline(std::cin, secao);
        
        std::string itens_line;
        std::getline(std::cin, itens_line);
        
        std::istringstream iss(itens_line);
        std::string item;
        
        while (iss >> item) {
            supermercado[secao].insert(item);
        }
    }
    
    std::string consulta;
    while (std::getline(std::cin, consulta) && consulta != "FIM") {
        std::istringstream iss(consulta);
        std::string secao, item;
        std::getline(iss, secao, ',');
        std::getline(iss, item);
        
        if (supermercado.count(secao) > 0 && supermercado[secao].count(item) > 0) {
            std::cout << "Tem\n";
        } else {
            std::cout << "Indisponivel\n";
        }
    }
    
    return 0;
}
