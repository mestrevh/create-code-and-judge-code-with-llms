/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string has_rg, rg_date, has_ticket, ticket_date, seat;
        
        std::cin >> has_rg;
        std::cin >> rg_date;
        std::cin >> has_ticket;
        std::cin >> ticket_date;
        std::cin >> seat;

        if (has_rg == "Nao possui") {
            std::cout << "a saida e nessa direção\n";
        } else if (has_ticket == "Nao possui") {
            std::cout << "a recepição e nessa direção\n";
        } else if (rg_date != ticket_date) {
            std::cout << "190\n";
        } else {
            std::cout << "o seu assento e " << seat << " tenha um bom dia\n";
        }
    }

    return 0;
}
