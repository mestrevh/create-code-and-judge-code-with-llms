/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

std::string ClassificaAluno(double media, int faltas) {
    if (faltas > 10) {
        return "REPROVADO POR FALTAS";
    }
    
    if (media >= 9.5) {
        return "APROVADO COM LOUVOR";
    } else if (media >= 7.0) {
        return "APROVADO";
    } else {
        return "REPROVADO";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double media;
    int faltas;
    
    std::cin >> media >> faltas;
    
    std::cout << ClassificaAluno(media, faltas) << std::endl;
    
    return 0;
}
