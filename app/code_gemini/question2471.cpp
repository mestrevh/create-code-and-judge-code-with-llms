/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Order {
    std::string name;
    int time;
    int original_index;
};

bool compareOrders(const Order& a, const Order& b) {
    if (a.time != b.time) {
        return a.time < b.time;
    }
    return a.original_index < b.original_index;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M;
    std::cin >> M;

    std::vector<std::string> misplaced_from_previous;
    double total_orders_taken = 0;
    double correct_orders_delivered = 0;

    for (int i = 1; i <= M; ++i) {
        int P;
        std::cin >> P;

        std::vector<Order> bebidas;
        std::vector<Order> acompanhamentos;
        std::vector<Order> sobremesas;
        std::vector<std::string> misplaced_for_next;

        for (int j = 0; j < P; ++j) {
            std::string name, category;
            int time;
            std::cin >> name >> time >> category;

            total_orders_taken++;

            if ((j + 1) % 3 == 0) {
                misplaced_for_next.push_back(name);
            } else {
                correct_orders_delivered++;
                Order current_order = {name, time, j};
                if (category == "Bebida") {
                    bebidas.push_back(current_order);
                } else if (category == "Acompanhamento") {
                    acompanhamentos.push_back(current_order);
                } else {
                    sobremesas.push_back(current_order);
                }
            }
        }

        std::sort(bebidas.begin(), bebidas.end(), compareOrders);
        std::sort(acompanhamentos.begin(), acompanhamentos.end(), compareOrders);
        std::sort(sobremesas.begin(), sobremesas.end(), compareOrders);
        
        std::cout << "Mesa " << i << ":";
        
        std::vector<std::string> final_delivery_list;
        for (const auto& order : bebidas) {
            final_delivery_list.push_back(order.name);
        }
        for (const auto& order : acompanhamentos) {
            final_delivery_list.push_back(order.name);
        }
        for (const auto& order : sobremesas) {
            final_delivery_list.push_back(order.name);
        }
        for (const auto& name : misplaced_from_previous) {
            final_delivery_list.push_back(name);
        }

        for (size_t k = 0; k < final_delivery_list.size(); ++k) {
            if (k == 0) {
                std::cout << " ";
            } else {
                std::cout << ", ";
            }
            std::cout << final_delivery_list[k];
        }
        std::cout << "\n";

        if (i < M) {
            misplaced_from_previous = misplaced_for_next;
        }
    }

    double percentage = 0.0;
    if (total_orders_taken > 0) {
        percentage = (correct_orders_delivered / total_orders_taken) * 100.0;
    }

    if (percentage < 70.0) {
        std::cout << "Eu preciso esquecer o Ross, vou ligar pra ele e falar que eu o superei.\n";
    } else if (percentage < 85.0) {
        std::cout << "Not bad, e so um trabalho temporario mesmo.\n";
    } else {
        std::cout << "That's what I call closure, Ross!\n";
    }

    return 0;
}
