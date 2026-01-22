/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long codigo;
    double n1, n2, n3;

    while (true) {
        std::cout << "Informe o codigo do aluno: (0 para encerrar o programa)\n";
        std::cin >> codigo;

        if (codigo == 0) {
            break;
        }

        std::cout << "Informe a primeira nota do aluno:\n";
        std::cin >> n1;

        std::cout << "Informe a segunda nota do aluno:\n";
        std::cin >> n2;

        std::cout << "Informe a terceira nota do aluno:\n";
        std::cin >> n3;

        double media = (n1 + n2 + n3) / 3.0;

        if (media == static_cast<long long>(media)) {
             std::cout << std::fixed << std::setprecision(1);
        } else {
             std::cout << std::fixed << std::setprecision(2);
        }
        
        std::cout << "Media do aluno: " << media << "\n";
    }

    return 0;
}
