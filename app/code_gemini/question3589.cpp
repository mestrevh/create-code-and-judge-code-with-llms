/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int nota_objetiva;
    int nota_redacao;
    char sexo;

    int total_inscritos = 0;
    int total_aprovados = 0;
    int mulheres_aprovadas = 0;
    int homens_aprovados = 0;

    while (std::cin >> nota_objetiva && nota_objetiva >= 0) {
        while (nota_objetiva > 100) {
            std::cout << "Digite uma nota inferior a 100.\n";
            std::cin >> nota_objetiva;
        }

        std::cin >> nota_redacao;
        while (nota_redacao > 100) {
            std::cout << "Digite uma nota inferior a 100.\n";
            std::cin >> nota_redacao;
        }

        std::cin >> sexo;
        
        total_inscritos++;

        double media = (nota_objetiva + nota_redacao) / 2.0;

        if (media >= 60.0 && nota_objetiva > 40 && nota_redacao > 40) {
            total_aprovados++;
            if (sexo == 'F' || sexo == 'f') {
                mulheres_aprovadas++;
            } else if (sexo == 'M' || sexo == 'm') {
                homens_aprovados++;
            }
        }
    }

    std::cout << total_inscritos << " candidato(s) inscrito(s).\n";
    std::cout << total_aprovados << " candidato(s) aprovado(s).\n";
    std::cout << mulheres_aprovadas << " mulher(es) e " << homens_aprovados << " homem(ns).\n";

    return 0;
}
