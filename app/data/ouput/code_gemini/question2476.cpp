/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct Patient {
    std::string name;
    int priority;
    int arrival_time;

    bool operator<(const Patient& other) const {
        if (priority != other.priority) {
            return priority < other.priority;
        }
        return arrival_time > other.arrival_time;
    }
};

void solve_case() {
    int N;
    std::cin >> N;
    
    std::priority_queue<Patient> pq;
    int arrival_counter = 0;
    
    std::string command;
    while (std::cin >> command && command != "END") {
        if (command == "ARR") {
            std::string name;
            int priority;
            std::cin >> name >> priority;
            
            if (pq.size() < static_cast<size_t>(N)) {
                pq.push({name, priority, arrival_counter++});
                std::cout << name << ", pos " << pq.size() << std::endl;
            } else {
                std::cout << name << ", transferido" << std::endl;
            }
        } else if (command == "CLL") {
            if (!pq.empty()) {
                Patient called = pq.top();
                pq.pop();
                std::cout << called.name << ", atendimento" << std::endl;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T;
    std::cin >> T;
    
    for (int i = 1; i <= T; ++i) {
        std::cout << "Situação " << i << std::endl;
        std::cout << std::endl;

        solve_case();
        
        if (i < T) {
            std::cout << std::endl;
        }
    }
    
    return 0;
}
