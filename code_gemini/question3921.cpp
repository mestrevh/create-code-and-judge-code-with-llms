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

    int n;
    long long m;
    std::cin >> n >> m;

    int total_people = 4 * n;
    int current_x = 0;
    int current_y = 0;
    int current_z = 0;
    long long total_moves = 0;
    int people_delivered = 0;
    bool fuel_ran_out = false;

    for (int i = 1; i <= total_people; ++i) {
        std::string dest_str;
        std::cin >> dest_str;

        int dest_x = dest_str[0] - '0';
        int dest_y = dest_str[1] - '0';
        int dest_z = dest_str[2] - '0';

        int dx = dest_x - current_x;
        int dy = dest_y - current_y;
        int dz = dest_z - current_z;

        if (dx > 0) {
            for (int k = 0; k < dx; ++k) std::cout << 'd';
        } else {
            for (int k = 0; k < -dx; ++k) std::cout << 'e';
        }

        if (dy > 0) {
            for (int k = 0; k < dy; ++k) std::cout << 'c';
        } else {
            for (int k = 0; k < -dy; ++k) std::cout << 'b';
        }

        if (dz > 0) {
            for (int k = 0; k < dz; ++k) std::cout << 'f';
        } else {
            for (int k = 0; k < -dz; ++k) std::cout << 't';
        }
        std::cout << std::endl;

        long long moves_this_trip = std::abs(dx) + std::abs(dy) + std::abs(dz);
        total_moves += moves_this_trip;
        
        people_delivered++;

        current_x = dest_x;
        current_y = dest_y;
        current_z = dest_z;

        std::cout << "Entregue " << i << " no quarto " << dest_str << " com " << total_moves << " movimentos." << std::endl;

        if (total_moves > m) {
            fuel_ran_out = true;
            break;
        }
    }

    if (fuel_ran_out) {
        std::cout << "Faltou combustível e foram entregues " << people_delivered << " pessoas." << std::endl;
    } else {
        std::cout << "Todas as pessoas foram entregues." << std::endl;
    }
    
    std::cout << "Fim do teste. Obrigado Kanye West!" << std::endl;

    return 0;
}
