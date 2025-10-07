/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int total_esforco = 0;
    bool dobrar_proximo = false;

    for (int dia = 0; dia < 5; ++dia) {
        char c;
        std::cin >> c;

        int horas;
        bool is_C_day = false;

        if (c == 'C') {
            std::cin >> horas;
            is_C_day = true;
        } else {
            horas = c - '0';
        }

        int esforco_dia;

        if (is_C_day) {
            esforco_dia = horas * 3;
        } else {
            if (dia == 0) { // Monday
                esforco_dia = horas * 2;
            } else if (dia == 4) { // Friday
                esforco_dia = horas / 2;
            } else { // Tue, Wed, Thu
                esforco_dia = horas;
            }
        }

        if (dobrar_proximo) {
            esforco_dia *= 2;
        }

        total_esforco += esforco_dia;

        if (is_C_day && dia < 4) {
            dobrar_proximo = true;
        } else {
            dobrar_proximo = false;
        }
    }

    if (total_esforco > 40) {
        std::cout << "DESCANSE LEAFAR, JA FOI SUFICIENTE\n";
    } else if (total_esforco == 40) {
        std::cout << "Descansou bem Leafar.\n";
    } else {
        std::cout << "Só quer mamata...\n";
    }

    return 0;
}
