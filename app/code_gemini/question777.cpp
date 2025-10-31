/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int patient_code;
    std::string dna_sequence;

    int max_t_count = -1;
    int strongest_patient_code = 0;

    while (std::cin >> patient_code && patient_code != 9999) {
        std::cin >> dna_sequence;

        int current_t_count = 0;
        for (char base : dna_sequence) {
            if (base == 'T') {
                current_t_count++;
            }
        }

        if (current_t_count > max_t_count) {
            max_t_count = current_t_count;
            strongest_patient_code = patient_code;
        }
    }

    std::cout << strongest_patient_code << std::endl;

    return 0;
}
