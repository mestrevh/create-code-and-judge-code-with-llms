/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int best_event_num = 1;
    int max_knockouts = -1;

    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        int current_knockouts = 0;

        for (int j = 0; j < x; ++j) {
            std::string def_name, cha_name;
            int def_g, def_s, def_c;
            int cha_g, cha_s, cha_c;

            std::cin >> def_name >> def_g >> def_s >> def_c 
                     >> cha_name >> cha_g >> cha_s >> cha_c;

            std::string winner_name;
            std::string method;

            if (cha_g > def_s) {
                winner_name = cha_name;
                method = "submissao";
            } else if (def_s > cha_g) {
                winner_name = def_name;
                method = "nocaute";
                current_knockouts++;
            } else if (cha_s > def_g) {
                winner_name = cha_name;
                method = "nocaute";
                current_knockouts++;
            } else if (def_g > cha_s) {
                winner_name = def_name;
                method = "submissao";
            } else if (cha_c > def_c) {
                winner_name = cha_name;
                method = "decisao";
            } else {
                winner_name = def_name;
                method = "decisao";
            }
            
            std::cout << winner_name << " ganhou por " << method << "\n";
        }

        if (current_knockouts > max_knockouts) {
            max_knockouts = current_knockouts;
            best_event_num = i;
        }
    }

    std::cout << "Melhor evento foi " << best_event_num << "\n";

    return 0;
}
