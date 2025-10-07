/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int exam_count = 0;
    int consultation_count = 0;
    double total_cost = 0.0;
    
    const int free_exams = 2;
    const int free_consultations = 3;
    const double exam_copay_percentage = 0.60;
    const double consultation_copay_percentage = 0.30;

    for (int i = 0; i < 8; ++i) {
        std::string type;
        double value;
        std::cin >> type >> value;

        if (type == "exame") {
            exam_count++;
            if (exam_count > free_exams) {
                total_cost += value * exam_copay_percentage;
            }
        } else {
            consultation_count++;
            if (consultation_count > free_consultations) {
                total_cost += value * consultation_copay_percentage;
            }
        }
    }

    std::cout << std::fixed << std::setprecision(2) << total_cost << std::endl;

    return 0;
}
