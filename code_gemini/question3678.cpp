/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long sake_bottles, manjus_brought, yakitoris_brought, people;
    std::cin >> sake_bottles >> manjus_brought >> yakitoris_brought >> people;

    long long sake_cups_needed = people * 4;
    long long manjus_needed = people * 5;
    long long yakitoris_needed = people * 3;

    long long sake_cups_available = sake_bottles * 15;

    long long sake_deficit = 0;
    if (sake_cups_needed > sake_cups_available) {
        sake_deficit = sake_cups_needed - sake_cups_available;
    }

    long long manjus_deficit = 0;
    if (manjus_needed > manjus_brought) {
        manjus_deficit = manjus_needed - manjus_brought;
    }

    long long yakitoris_deficit = 0;
    if (yakitoris_needed > yakitoris_brought) {
        yakitoris_deficit = yakitoris_needed - yakitoris_brought;
    }

    int missing_count = 0;
    if (sake_deficit > 0) missing_count++;
    if (manjus_deficit > 0) missing_count++;
    if (yakitoris_deficit > 0) missing_count++;

    if (missing_count == 0) {
        std::cout << "Partiu Festa do Japa!" << std::endl;
    } else if (missing_count == 3) {
        std::cout << "Partiu Festa do Japa...Japacama" << std::endl;
    } else if (missing_count == 1) {
        std::cout << "Faltaram ";
        if (sake_deficit > 0) {
            std::cout << sake_deficit << " saques" << std::endl;
        } else if (manjus_deficit > 0) {
            std::cout << manjus_deficit << " manjus" << std::endl;
        } else {
            std::cout << yakitoris_deficit << " yakitoris" << std::endl;
        }
    } else { // missing_count == 2
        std::cout << "Faltaram ";
        if (sake_deficit > 0) {
            std::cout << sake_deficit << " saques e ";
            if (manjus_deficit > 0) {
                std::cout << manjus_deficit << " manjus" << std::endl;
            } else {
                std::cout << yakitoris_deficit << " yakitoris" << std::endl;
            }
        } else {
            std::cout << manjus_deficit << " manjus e " << yakitoris_deficit << " yakitoris" << std::endl;
        }
    }

    return 0;
}
