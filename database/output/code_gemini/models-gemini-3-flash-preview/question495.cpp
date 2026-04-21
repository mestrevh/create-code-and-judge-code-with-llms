/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int student_count;
    while (std::cin >> student_count) {
        long long total_students = student_count;
        for (int i = 0; i < 6; ++i) {
            if (std::cin >> student_count) {
                total_students += student_count;
            }
        }

        long long total_staples = total_students * 4;
        long long total_boxes = (total_staples + 29) / 30;

        std::cout << total_staples << "\n" << total_boxes << "\n";
    }

    return 0;
}