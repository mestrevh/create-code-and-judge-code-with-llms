/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n1;
    std::cin >> n1;

    int num_chairs = 0;
    int p_len = 0;
    std::vector<std::string> chairs_vec;

    for (int i = 0; i < n1; ++i) {
        std::string bin_str;
        std::cin >> bin_str;

        if (i == 0) {
            int s = bin_str.length();
            p_len = static_cast<int>(log2(s));
            num_chairs = s;
            chairs_vec.assign(num_chairs, "");
        }
        
        std::string pos_str = bin_str.substr(0, p_len);
        std::string id_str = bin_str.substr(p_len);
        int target_pos = std::stoul(pos_str, nullptr, 2);

        int current_pos = target_pos;
        while (!chairs_vec[current_pos].empty()) {
            current_pos = (current_pos + 1) % num_chairs;
        }
        chairs_vec[current_pos] = id_str;
    }

    int n2;
    std::cin >> n2;

    for (int i = 0; i < n2; ++i) {
        int query_pos;
        std::cin >> query_pos;

        if (query_pos >= 0 && query_pos < num_chairs && !chairs_vec[query_pos].empty()) {
            std::cout << chairs_vec[query_pos] << "\n";
        } else {
            std::cout << "Nao tem ninguem\n";
        }
    }

    return 0;
}
