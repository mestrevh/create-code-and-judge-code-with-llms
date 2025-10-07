/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char continue_char;
    int year;
    double speed;

    int newest_year = 0;
    double fastest_speed = 0.0;
    double total_speed = 0.0;
    int car_count = 0;

    while (std::cin >> continue_char && (continue_char == 's' || continue_char == 'S')) {
        std::cin >> year >> speed;

        if (car_count == 0) {
            newest_year = year;
            fastest_speed = speed;
        } else {
            if (year > newest_year) {
                newest_year = year;
            }
            if (speed > fastest_speed) {
                fastest_speed = speed;
            }
        }

        total_speed += speed;
        car_count++;
    }

    if (car_count == 0) {
        std::cout << "zero" << std::endl;
    } else {
        double average_speed = total_speed / car_count;

        std::cout << std::fixed << std::setprecision(2);
        std::cout << fastest_speed << std::endl;
        std::cout << newest_year << std::endl;
        std::cout << average_speed << std::endl;
    }

    return 0;
}
