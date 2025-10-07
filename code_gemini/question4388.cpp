/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int count_to_replace = 0;
    std::string plate;
    while (n--) {
        std::cin >> plate;
        if (plate.length() == 7 && isalpha(plate[0]) && isalpha(plate[1]) && isalpha(plate[2]) && isdigit(plate[3]) && isdigit(plate[4]) && isdigit(plate[5]) && isdigit(plate[6])) {
            count_to_replace++;
        }
    }
    std::cout << count_to_replace << std::endl;
    return 0;
}
