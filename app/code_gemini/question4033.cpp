/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double n1, n2, n3;
    char gender;

    double highest_avg = -1.0;
    char highest_avg_gender = ' ';

    double total_sum = 0.0;
    int total_students = 0;

    int approved_count = 0;
    int final_exam_count = 0;
    int failed_count = 0;

    double female_sum = 0.0;
    int female_count = 0;

    double male_sum = 0.0;
    int male_count = 0;

    while (std::cin >> n1 >> n2 >> n3 >> gender) {
        double avg = (n1 + n2 + n3) / 3.0;

        total_students++;
        total_sum += avg;

        if (avg >= highest_avg) {
            highest_avg = avg;
            highest_avg_gender = gender;
        }

        if (avg >= 7.0) {
            approved_count++;
        } else if (avg >= 3.0) {
            final_exam_count++;
        } else {
            failed_count++;
        }

        if (gender == 'M') {
            female_sum += avg;
            female_count++;
        } else {
            male_sum += avg;
            male_count++;
        }
    }

    if (total_students > 0) {
        double overall_avg = total_sum / total_students;
        double female_avg = (female_count > 0) ? (female_sum / female_count) : 0.0;
        double male_avg = (male_count > 0) ? (male_sum / male_count) : 0.0;

        std::cout << std::fixed << std::setprecision(1);

        std::cout << "A maior media da turma foi " << highest_avg << " e pertence a "
                  << (highest_avg_gender == 'M' ? "uma mulher." : "um homem.") << std::endl;
        std::cout << "A media geral foi de " << overall_avg << "." << std::endl;
        std::cout << approved_count << " alunos foram aprovados por media." << std::endl;
        std::cout << final_exam_count << " alunos podem fazer o exame final." << std::endl;
        std::cout << failed_count << " alunos foram reprovados." << std::endl;
        std::cout << "A media das mulheres foi de " << female_avg << "." << std::endl;
        std::cout << "A media dos homens foi de " << male_avg << "." << std::endl;
    }

    return 0;
}
