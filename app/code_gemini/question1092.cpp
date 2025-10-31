/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int homens_count = 0;
    int mulheres_count = 0;
    double homens_salario_total = 0.0;
    double salario_total = 0.0;
    double maior_salario = -1.0;
    char sexo_maior_salario = ' ';

    for (int i = 0; i < 10; ++i) {
        char sexo;
        double salario;
        
        std::cin >> salario;
        std::cin >> sexo;

        salario_total += salario;

        if (sexo == 'm') {
            homens_count++;
            homens_salario_total += salario;
        } else if (sexo == 'f') {
            mulheres_count++;
        }

        if (salario > maior_salario) {
            maior_salario = salario;
            sexo_maior_salario = sexo;
        }
    }

    std::cout << homens_count << std::endl;
    std::cout << mulheres_count << std::endl;

    double media_total = 0.0;
    if (homens_count + mulheres_count > 0) {
        media_total = salario_total / (homens_count + mulheres_count);
    }
    std::cout << std::fixed << std::setprecision(1) << media_total << std::endl;

    std::cout << sexo_maior_salario << std::endl;

    double media_homens = 0.0;
    if (homens_count > 0) {
        media_homens = homens_salario_total / homens_count;
    }
    std::cout << std::fixed << std::setprecision(1) << media_homens << std::endl;

    return 0;
}
