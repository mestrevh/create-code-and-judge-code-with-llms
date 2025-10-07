/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string phrase;
    std::getline(std::cin, phrase);

    int count_a = 0;
    int count_e = 0;
    int count_i = 0;
    int count_o = 0;
    int count_u = 0;
    int total_letters = 0;

    for (char c : phrase) {
        if (isalpha(c)) {
            total_letters++;
            char lower_c = tolower(c);
            switch (lower_c) {
                case 'a':
                    count_a++;
                    break;
                case 'e':
                    count_e++;
                    break;
                case 'i':
                    count_i++;
                    break;
                case 'o':
                    count_o++;
                    break;
                case 'u':
                    count_u++;
                    break;
            }
        }
    }

    std::cout << "a " << count_a << std::endl;
    std::cout << "e " << count_e << std::endl;
    std::cout << "i " << count_i << std::endl;
    std::cout << "o " << count_o << std::endl;
    std::cout << "u " << count_u << std::endl;

    int total_vowels = count_a + count_e + count_i + count_o + count_u;
    double percentage = 0.0;

    if (total_letters > 0) {
        percentage = (static_cast<double>(total_vowels) / total_letters) * 100.0;
    }

    std::cout << std::fixed << std::setprecision(2) << percentage << "%" << std::endl;

    return 0;
}
