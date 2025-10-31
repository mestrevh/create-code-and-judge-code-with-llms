/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    int num_questoes;
    std::cin >> num_questoes;
    std::string gabarito;
    std::cin >> gabarito;
    int num_alunos;
    std::cin >> num_alunos;
    
    std::vector<int> notas(num_alunos);
    
    for (int i = 0; i < num_alunos; ++i) {
        std::string resposta;
        std::cin >> resposta;
        int nota = 0;
        
        for (int j = 0; j < num_questoes; ++j) {
            if (resposta[j] == gabarito[j]) {
                nota++;
            }
        }
        notas[i] = nota;
    }
    
    for (int nota : notas) {
        std::cout << nota << std::endl;
    }
    
    return 0;
}
