/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct Patient {
    string name;
    int priority;
    
    bool operator<(const Patient& other) const {
        return priority > other.priority;
    }
};

int main() {
    int T;
    cin >> T;
    cin.ignore();

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        cin.ignore();
        
        priority_queue<Patient> queue;
        vector<string> output;
        string command;
        
        output.push_back("Situação " + to_string(t));

        while (true) {
            getline(cin, command);
            if (command == "END") break;

            stringstream ss(command);
            string action;
            ss >> action;

            if (action == "ARR") {
                string name;
                int priority;
                ss >> name >> priority;

                if (queue.size() < N) {
                    queue.push({name, priority});
                    output.push_back(name + ", pos " + to_string(queue.size()));
                } else {
                    output.push_back(name + ", transferido");
                }
            } else if (action == "CLL") {
                if (!queue.empty()) {
                    Patient next = queue.top();
                    queue.pop();
                    output.push_back(next.name + ", atendimento");
                }
            }
        }

        for (const string& line : output) {
            cout << line << endl;
        }
    }

    return 0;
}
