/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<int, int> flights;
    int flight_num, seat_count;

    std::cout << "Digite o numero do voo e a quantidade de lugares disponiveis:\n";

    for (int i = 0; i < 37; ++i) {
        std::cin >> flight_num >> seat_count;
        flights[flight_num] = seat_count;
    }

    int requested_flight;
    while (true) {
        std::cout << "Digite o pedido de reserva:\n";
        std::cin >> requested_flight;

        if (requested_flight == 9999) {
            break;
        }

        auto it = flights.find(requested_flight);

        if (it != flights.end()) {
            if (it->second > 0) {
                std::cout << "Voo " << requested_flight << " DISPONIVEL\n";
                it->second--;
            } else {
                std::cout << "Voo " << requested_flight << " INDISPONIVEL\n";
            }
        } else {
            std::cout << "Voo " << requested_flight << " INDISPONIVEL\n";
        }
    }

    return 0;
}
