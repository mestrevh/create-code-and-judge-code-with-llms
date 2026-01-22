/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

std::string Plantar_e_Colher(int dia, int mes) {
    if ((mes == 10 && dia >= 1) || (mes == 11)) {
        return "Hora de plantar milho e soja";
    } else if ((mes == 1 && dia >= 1 && dia <= 31) || (mes == 2 && dia <= 15)) {
        return "Hora de colher manga";
    } else if ((mes == 1 && dia >= 25) || (mes == 2 && dia >= 16)) {
        return "Hora de colher cebola";
    } else if ((mes == 2 && dia >= 16) || (mes == 3 && dia <= 31)) {
        return "Hora de plantar batata";
    } else if ((mes == 8 && dia >= 15) || (mes == 9 && dia <= 30)) {
        return "Hora de colher cenoura";
    }
    return "Sem atividade específica";
}

int main() {
    int dia, mes;
    std::cin >> dia >> mes;
    std::cout << Plantar_e_Colher(dia, mes) << std::endl;
    return 0;
}
