/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int totalSoldados = 0;
    float alturaMaisAltoCV = 0.0f;
    int lanceirosStark = 0;
    int idadeArqueiroMaisJovemO = 999;
    char sexoEspadachimMaisAltoP = 'X';

    float alturaEspadachimMaisAltoP = 0.0f;

    char casa, sexo, habilidade;
    int idade;
    float altura;

    while (std::cin >> casa && (casa == 'S' || casa == 'P' || casa == 'C' || casa == 'O')) {
        std::cin >> sexo >> idade >> altura >> habilidade;

        totalSoldados++;

        if (casa == 'C') {
            if (altura > alturaMaisAltoCV) {
                alturaMaisAltoCV = altura;
            }
        }

        if (casa == 'S' && habilidade == 'l') {
            lanceirosStark++;
        }
        
        if (casa == 'O' && habilidade == 'a') {
            if (idade < idadeArqueiroMaisJovemO) {
                idadeArqueiroMaisJovemO = idade;
            }
        }

        if (casa == 'P' && habilidade == 'e') {
            if (altura > alturaEspadachimMaisAltoP) {
                alturaEspadachimMaisAltoP = altura;
                sexoEspadachimMaisAltoP = sexo;
            }
        }
    }

    std::cout << totalSoldados << std::endl;
    std::cout << std::fixed << std::setprecision(2) << alturaMaisAltoCV << std::endl;
    std::cout << lanceirosStark << std::endl;
    std::cout << idadeArqueiroMaisJovemO << std::endl;
    std::cout << sexoEspadachimMaisAltoP << std::endl;

    return 0;
}
