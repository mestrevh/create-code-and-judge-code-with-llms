/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h1, m1, h2, m2;

    while (std::cin >> h1 >> m1 >> h2 >> m2) {
        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) {
            break;
        }

        int current_time_in_minutes = h1 * 60 + m1;
        int alarm_time_in_minutes = h2 * 60 + m2;

        int minutes_to_sleep;

        if (alarm_time_in_minutes > current_time_in_minutes) {
            minutes_to_sleep = alarm_time_in_minutes - current_time_in_minutes;
        } else {
            minutes_to_sleep = (24 * 60 - current_time_in_minutes) + alarm_time_in_minutes;
        }

        std::cout << minutes_to_sleep << '\n';
    }

    return 0;
}
