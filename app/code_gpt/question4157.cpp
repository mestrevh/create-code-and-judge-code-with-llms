/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>

std::string classificaIAF(double iaf) {
    if (iaf < 100) return "Sem volta";
    if (iaf < 500) return "Conserta Impressoras";
    return "Morador do Grad";
}

int main() {
    std::vector<std::tuple<int, double, double>> alunos(3);
    
    for (int i = 0; i < 3; ++i) {
        int x, y, k;
        std::cin >> x >> y >> k;
        double iaf = (x * 100.0) / (1 + (0.25 * y));
        alunos[i] = std::make_tuple(k, iaf, classificaIAF(iaf));
    }
    
    for (const auto& aluno : alunos) {
        std::cout << "O aluno de índice " << std::get<0>(aluno) 
                  << " possui o valor IAF igual a " << std::fixed << std::setprecision(2) 
                  << std::get<1>(aluno) << " e a descrição de " << std::get<2>(aluno) << ".\n";
    }
    
    return 0;
}
