/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>

struct Student {
    std::string name;
    int monitor_id;
    std::vector<int> questions;
    int final_score;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a;
    std::cin >> a;

    std::map<int, std::string> monitor_map;
    for (int i = 0; i < a; ++i) {
        std::string monitor_name;
        int monitor_id;
        std::cin >> monitor_name >> monitor_id;
        monitor_map[monitor_id] = monitor_name;
    }

    int b;
    std::cin >> b;

    std::vector<Student> students(b);
    for (int i = 0; i < b; ++i) {
        std::cin >> students[i].name >> students[i].monitor_id;
    }

    for (int i = 0; i < b; ++i) {
        students[i].questions.resize(9);
        for (int j = 0; j < 9; ++j) {
            std::cin >> students[i].questions[j];
        }
    }

    int n;
    std::cin >> n;

    int bonus_question_index = (n * 3) - 1;

    for (int i = 0; i < b; ++i) {
        int base_score = 0;
        for (int score : students[i].questions) {
            base_score += score;
        }
        
        students[i].final_score = base_score;
        if (students[i].questions[bonus_question_index] == 1) {
            students[i].final_score++;
        }
    }

    for (int i = 0; i < b; ++i) {
        std::cout << students[i].name << "\n";
        std::cout << monitor_map[students[i].monitor_id] << "\n";
        std::cout << students[i].final_score << "\n";
    }

    return 0;
}
