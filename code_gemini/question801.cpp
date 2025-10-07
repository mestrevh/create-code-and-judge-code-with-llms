/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

std::string AnalisarSituacao(double n1, double n2, double n3, double n4) {
    double media = (n1 * 1 + n2 * 2 + n3 * 3 + n4 * 4) / 10.0;
    
    if (media >= 9.0) {
        return "aprovado com louvor";
    } else if (media >= 7.0) {
        return "aprovado";
    } else if (media < 3.0) {
        return "reprovado";
    } else {
        return "prova final";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double n1, n2, n3, n4;
    std::cin >> n1 >> n2 >> n3 >> n4;
    
    std::cout << AnalisarSituacao(n1, n2, n3, n4) << std::endl;
    
    return 0;
}
