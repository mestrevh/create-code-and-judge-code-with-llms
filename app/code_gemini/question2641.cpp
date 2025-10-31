/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int calculate_hours(long long euros_needed, int current_hour, int initial_speed, int num_machines) {
    long long speed_this_hour = initial_speed + (long long)(current_hour - 1) * 100;
    long long production_this_hour = speed_this_hour * num_machines;

    if (euros_needed <= production_this_hour) {
        return current_hour;
    }

    return calculate_hours(euros_needed - production_this_hour, current_hour + 1, initial_speed, num_machines);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long e;
    int x, n;
    std::cin >> e >> x >> n;

    if (e <= 0) {
        std::cout << "Precisamos de 0 horas para conseguirmos imprimir " << e << " euros." << std::endl;
    } else {
        int hours = calculate_hours(e, 1, x, n);
        std::cout << "Precisamos de " << hours << " horas para conseguirmos imprimir " << e << " euros." << std::endl;
    }

    return 0;
}
