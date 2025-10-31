/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    getline(std::cin, line);

    char i0 = line[0];
    char i1 = line[1];
    char i2 = line[2];
    char i3 = line[3];
    char i4 = line[4];
    char i5 = line[5];
    char i6 = line[6];

    bool is_valid = true;

    if (!((i0 == '.' || i0 == ':') && i0 == i6)) {
        is_valid = false;
    }

    if (!(i1 == 'b' || i1 == 'f' || i1 == 'p' || i1 == ' ')) {
        is_valid = false;
    }

    if (!(i2 == 'A' || i2 == 'T' || i2 == 'C' || i2 == 'R' || i2 == ' ')) {
        is_valid = false;
    }

    if (!(i3 == 'A' || i3 == 'T' || i3 == 'C' || i3 == 'R' || i3 == ' ')) {
        is_valid = false;
    }

    if (!(i4 == 'A' || i4 == 'T' || i4 == 'C' || i4 == 'R' || i4 == ' ')) {
        is_valid = false;
    }

    bool sauce_is_wrong = (i5 != 'P');
    if (sauce_is_wrong) {
        is_valid = false;
    }

    if (is_valid) {
        std::cout << "Valido\n";
    } else {
        std::cout << "Invalido\n";
        if (sauce_is_wrong) {
            std::cout << "...Mas pelo menos ganhou um chute\n";
        }
    }

    return 0;
}
