/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int countOccurrences(const std::string& sequence, char target) {
    int count = 0;
    for (char c : sequence) {
        if (c == target) {
            count++;
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string sequence;
    std::getline(std::cin, sequence);

    char target_char;
    std::cin >> target_char;

    int occurrences = countOccurrences(sequence, target_char);

    if (occurrences > 0) {
        std::cout << "O caractere buscado ocorre " << occurrences << " vezes na sequencia." << std::endl;
    } else {
        std::cout << "Caractere nao encontrado." << std::endl;
    }

    return 0;
}
