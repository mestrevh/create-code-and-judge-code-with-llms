/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int age;
    int max_age = -1;
    int total_people = 0;
    int qualifying_women = 0;

    while (std::cin >> age && age != -1) {
        char sex, hair, eyes;
        std::cin >> sex >> hair >> eyes;

        total_people++;

        if (age > max_age) {
            max_age = age;
        }

        if (sex == 'f' && eyes == 'v' && hair == 'l' && age >= 18 && age <= 35) {
            qualifying_women++;
        }
    }

    double percentage = 0.0;
    if (total_people > 0) {
        percentage = static_cast<double>(qualifying_women) / total_people * 100.0;
    }

    std::cout << "Mais velho: " << max_age << std::endl;
    std::cout << "Mulheres com olhos verdes, loiras com 18 a 35 anos: "
              << std::fixed << std::setprecision(2) << percentage << "%" << std::endl;

    return 0;
}
