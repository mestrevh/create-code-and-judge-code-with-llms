/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Task {
    int priority;
    string description;
};

bool compareTasks(const Task& a, const Task& b) {
    if (a.priority != b.priority) {
        return a.priority < b.priority;
    }
    return false; 
}

int main() {
    int option;
    vector<Task> tasks;

    while (cin >> option && option != 0) {
        if (option == 1) {
            string description;
            int priority;
            cin.ignore(); 
            getline(cin, description);
            cin >> priority;
            tasks.push_back({priority, description});
        } else if (option == 2) {
            stable_sort(tasks.begin(), tasks.end(), compareTasks);
            cout << endl;
            for (const auto& task : tasks) {
                cout << task.priority << ". " << task.description << endl;
            }
        }
    }

    return 0;
}
