/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

struct Voto {
    std::string nome;
    int agregados;
    std::string comida;
    std::string bebida;
    std::string atração;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Voto> votos(n);
    std::map<std::string, int> comidaVotes, bebidaVotes, atraçãoVotes;
    
    for (int i = 0; i < n; ++i) {
        std::cin >> votos[i].nome >> votos[i].agregados;
        std::string lixo;
        std::getline(std::cin >> std::ws, lixo); 
        votos[i].comida = lixo.substr(0, lixo.find_last_of(' ')); 
        votos[i].bebida = lixo.substr(lixo.find_last_of(' ') + 1);
        std::getline(std::cin >> std::ws, votos[i].atração);
        
        comidaVotes[votos[i].comida]++;
        bebidaVotes[votos[i].bebida]++;
        atraçãoVotes[votos[i].atração]++;
    }

    std::string comidaVencedora, bebidaVencedora, atraçãoVencedora;
    int maxComidaVotes = 0, maxBebidaVotes = 0, maxAtraçãoVotes = 0;

    for (const auto& [key, value] : comidaVotes) {
        if (value > maxComidaVotes || (value == maxComidaVotes && key < comidaVencedora)) {
            maxComidaVotes = value;
            comidaVencedora = key;
        }
    }
    for (const auto& [key, value] : bebidaVotes) {
        if (value > maxBebidaVotes || (value == maxBebidaVotes && key < bebidaVencedora)) {
            maxBebidaVotes = value;
            bebidaVencedora = key;
        }
    }
    for (const auto& [key, value] : atraçãoVotes) {
        if (value > maxAtraçãoVotes || (value == maxAtraçãoVotes && key < atraçãoVencedora)) {
            maxAtraçãoVotes = value;
            atraçãoVencedora = key;
        }
    }

    int minAgregados = INT_MAX;
    std::set<std::string> vipConvidados;
    
    for (const auto& voto : votos) {
        if (voto.comida == comidaVencedora) {
            if (voto.bebida == bebidaVencedora) {
                vipConvidados.insert(voto.nome);
            }
            if (voto.agregados < minAgregados) {
                minAgregados = voto.agregados;
            }
        }
    }

    std::cout << minAgregados << std::endl;
    std::cout << comidaVencedora << std::endl;
    std::cout << bebidaVencedora << std::endl;
    std::cout << atraçãoVencedora << std::endl;
    std::cout << "convidados vip:" << std::endl;

    for (const auto& nome : vipConvidados) {
        std::cout << nome << std::endl;
    }

    return 0;
}
