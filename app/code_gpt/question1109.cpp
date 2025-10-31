/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<int> programas(7), linhas(7);
    std::string dias[7] = {"DOMINGO", "SEGUNDA", "TERCA", "QUARTA", "QUINTA", "SEXTA", "SABADO"};
    
    for (int i = 0; i < 7; ++i) {
        std::cin >> programas[i] >> linhas[i];
    }
    
    int dias_programas = 0, dias_linhas = 0, max_linhas = linhas[0], dia_max = 0;
    
    for (int i = 0; i < 7; ++i) {
        if (programas[i] >= 5) dias_programas++;
        if (linhas[i] >= 100) dias_linhas++;
        if (linhas[i] > max_linhas) {
            max_linhas = linhas[i];
            dia_max = i;
        } else if (linhas[i] == max_linhas) {
            dia_max = i;
        }
    }
    
    std::cout << "QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: " << dias_programas << std::endl;
    std::cout << "QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: " << dias_linhas << std::endl;
    std::cout << "DIA QUE MAIS PRODUZIU: " << dias[dia_max] << std::endl;

    return 0;
}
