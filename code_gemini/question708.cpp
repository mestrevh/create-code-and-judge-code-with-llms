/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>

struct Truck {
    long long capacity;
    long long current_weight;
    std::stack<int> items;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    bool first_case = true;

    while (std::cin >> N) {
        if (!first_case) {
            std::cout << '\n';
        }
        first_case = false;

        std::vector<Truck> trucks(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> trucks[i].capacity;
            trucks[i].current_weight = 0;
        }

        std::queue<int> warehouse;
        long long warehouse_total_weight = 0;

        std::string dummy;
        std::getline(std::cin, dummy); 

        std::string line;
        while (std::getline(std::cin, line) && !line.empty()) {
            std::stringstream ss(line);
            std::string command;
            ss >> command;
            int i, w;

            if (command == "ADD") {
                ss >> w;
                warehouse.push(w);
                warehouse_total_weight += w;
                std::cout << warehouse.size() << " " << warehouse_total_weight << '\n';
            } else if (command == "LOA") {
                ss >> i;
                long long remaining_capacity = trucks[i].capacity - trucks[i].current_weight;
                while (!warehouse.empty()) {
                    int item_weight = warehouse.front();
                    if (item_weight <= remaining_capacity) {
                        warehouse.pop();
                        warehouse_total_weight -= item_weight;
                        
                        trucks[i].items.push(item_weight);
                        trucks[i].current_weight += item_weight;
                        remaining_capacity -= item_weight;
                    } else {
                        break;
                    }
                }
                std::cout << i << " " << trucks[i].items.size() << '\n';
            } else if (command == "DEL") {
                ss >> i;
                if (!trucks[i].items.empty()) {
                    int item_weight = trucks[i].items.top();
                    trucks[i].items.pop();
                    trucks[i].current_weight -= item_weight;
                }
                std::cout << i << " " << trucks[i].items.size() << '\n';
            } else if (command == "INF") {
                ss >> i;
                std::cout << i << " " << trucks[i].items.size() << " " << trucks[i].current_weight << '\n';
            }
        }
    }

    return 0;
}
