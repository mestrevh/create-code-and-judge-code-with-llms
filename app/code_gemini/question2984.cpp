/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double n1, n2, n3, frequencia;

    std::cin >> n1 >> n2 >> n3 >> frequencia;

    double media = (n1 * 2.0 + n2 * 2.0 + n3 * 3.0) / 7.0;
    double media_arredondada = round(media * 10.0) / 10.0;
    
    int freq_percent = static_cast<int>(frequencia * 100);

    std::cout << "Frequencia: " << freq_percent << "%" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Media: " << media_arredondada << std::endl;

    if (frequencia < 0.75) {
        std::cout << "Aluno reprovado por faltas!" << std::endl;
    } else {
        if (media_arredondada > 9.0) {
            std::cout << "Aluno aprovado com louvor!" << std::endl;
        } else if (media_arredondada >= 6.0) {
            std::cout << "Aluno aprovado!" << std::endl;
        } else if (media_arredondada >= 4.0) {
            std::cout << "Aluno de rec!" << std::endl;
        } else {
            std::cout << "Aluno reprovado!" << std::endl;
        }
    }

    return 0;
}
