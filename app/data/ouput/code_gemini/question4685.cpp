/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

struct Task {
    std::string description;
    int priority;
    int insertion_id;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<Task> tasks;
    int id_counter = 0;
    int option;

    while (std::cin >> option && option != 0) {
        if (option == 1) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string desc;
            std::getline(std::cin, desc);
            int prio;
            std::cin >> prio;
            tasks.push_back({desc, prio, id_counter++});
        } else if (option == 2) {
            std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
                if (a.priority != b.priority) {
                    return a.priority < b.priority;
                }
                return a.insertion_id > b.insertion_id;
            });

            std::cout << "\n";
            for (const auto& task : tasks) {
                std::cout << task.priority << ". " << task.description << "\n";
            }
        }
    }

    return 0;
}
