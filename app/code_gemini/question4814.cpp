/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int key = 0;
    if (n > 1) {
        int temp_n = n;
        while (temp_n % 2 == 0) {
            key++;
            temp_n /= 2;
        }
        for (int i = 3; i <= std::sqrt(temp_n); i += 2) {
            while (temp_n % i == 0) {
                key++;
                temp_n /= i;
            }
        }
        if (temp_n > 2) {
            key++;
        }
    }

    std::cout << key << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string s;
    std::getline(std::cin, s);

    int pa_increment = 0;
    for (char &c : s) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            int shift = key + pa_increment;
            char base = std::islower(static_cast<unsigned char>(c)) ? 'a' : 'A';
            c = base + (c - base + shift) % 26;
            pa_increment++;
        }
    }

    std::cout << s << std::endl;

    return 0;
}
