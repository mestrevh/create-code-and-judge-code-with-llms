/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Tarefa {
    std::string descricao;
    int prioridade;

    bool operator<(const Tarefa& other) const {
        if (prioridade == other.prioridade) return false;
        return prioridade < other.prioridade;
    }
};

int main() {
    std::vector<Tarefa> tarefas;
    int opcao;
    
    while (true) {
        std::cin >> opcao;
        if (opcao == 0) break;
        
        if (opcao == 1) {
            Tarefa novaTarefa;
            std::cin.ignore();
            std::getline(std::cin, novaTarefa.descricao);
            std::cin >> novaTarefa.prioridade;
            tarefas.push_back(novaTarefa);
        }
        
        if (opcao == 2) {
            std::sort(tarefas.rbegin(), tarefas.rend(), [](const Tarefa& a, const Tarefa& b) {
                return a.prioridade < b.prioridade || (a.prioridade == b.prioridade && a.descricao > b.descricao);
            });

            std::cout << std::endl;
            for (const auto& tarefa : tarefas) {
                std::cout << tarefa.prioridade << ". " << tarefa.descricao << std::endl;
            }
        }
    }
    
    return 0;
}
