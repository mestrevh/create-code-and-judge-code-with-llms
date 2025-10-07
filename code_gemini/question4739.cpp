/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>

struct Subject {
    std::string name;
    std::stack<std::string> activities;
};

void display(const std::deque<Subject>& subjects_queue) {
    for (const auto& subject : subjects_queue) {
        std::cout << "Materia: " << subject.name << std::endl;

        std::stack<std::string> temp_stack = subject.activities;
        std::vector<std::string> reversed_activities;
        if (!temp_stack.empty()) {
            reversed_activities.reserve(temp_stack.size());
            while (!temp_stack.empty()) {
                reversed_activities.push_back(temp_stack.top());
                temp_stack.pop();
            }
            std::reverse(reversed_activities.begin(), reversed_activities.end());
        }

        for (const auto& activity : reversed_activities) {
            std::cout << "    Atividade: " << activity << std::endl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::deque<Subject> subjects_queue;
    std::string line;

    while (std::getline(std::cin, line) && !line.empty()) {
        if (line.length() >= 2 && line.substr(0, 2) == "M ") {
            subjects_queue.push_back({line.substr(2), {}});
        } else if (line.length() >= 2 && line.substr(0, 2) == "A ") {
            if (!subjects_queue.empty()) {
                subjects_queue.back().activities.push(line.substr(2));
            }
        }
    }

    bool first_output_has_been_printed = false;
    while (true) {
        if (subjects_queue.empty()) {
            break;
        }

        Subject& front_subject = subjects_queue.front();
        if (front_subject.activities.empty()) {
            subjects_queue.pop_front();
        } else {
            front_subject.activities.pop();
        }

        if (subjects_queue.empty()) {
            break;
        }

        if (first_output_has_been_printed) {
            std::cout << "_________________\n";
        }

        display(subjects_queue);
        first_output_has_been_printed = true;
    }

    return 0;
}
