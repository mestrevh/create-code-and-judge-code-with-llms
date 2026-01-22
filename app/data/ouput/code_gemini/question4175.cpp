/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdio>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int d1, m1, d_today, m_today;
    if (scanf("%d/%d - %d/%d", &d1, &m1, &d_today, &m_today) != 4) {
        return 1;
    }

    int T;
    double lat, lon;
    std::cin >> T >> lat >> lon;

    int first_murder_day = (m1 - 1) * 30 + d1;
    int today = (m_today - 1) * 30 + d_today;

    int next_murder_day = first_murder_day;
    while (next_murder_day <= today) {
        next_murder_day += T;
    }

    double final_lat = lat;
    double final_lon = lon;

    for (int d = first_murder_day; d < next_murder_day; d += T) {
        final_lat += static_cast<double>(T) * std::cos(static_cast<double>(d));
        final_lon += static_cast<double>(T) * std::sin(static_cast<double>(d));
    }

    int out_m = (next_murder_day - 1) / 30 + 1;
    int out_d = (next_murder_day - 1) % 30 + 1;

    std::cout << "o proximo assassinato sera dia "
              << std::setw(2) << std::setfill('0') << out_d << "/"
              << std::setw(2) << std::setfill('0') << out_m << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "As coordenadas sao lat = " << final_lat << "°, long = " << final_lon << "°\n";

    return 0;
}
