/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

void to_upper(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::toupper(c); });
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int max_rating = -1;
    std::string fav_name;

    int min_rating = 101;
    std::string least_fav_name;

    for (int i = 0; i < n; ++i) {
        int current_rating;
        std::string current_name;
        std::cin >> current_rating >> current_name;

        if (current_rating > max_rating) {
            max_rating = current_rating;
            fav_name = current_name;
        }

        if (current_rating < min_rating) {
            min_rating = current_rating;
            least_fav_name = current_name;
        }
    }

    to_upper(fav_name);
    to_upper(least_fav_name);

    std::cout << "O favorito de Joao eh " << fav_name << " com " << max_rating << " rating!" << std::endl;
    std::cout << "O que Joao menos gosta eh " << least_fav_name << " com " << min_rating << " rating!" << std::endl;

    return 0;
}
