/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void handleQueue(int capacity, int& incubator_count, int& queue_count) {
    if (queue_count > 0 && incubator_count < capacity) {
        int space = capacity - incubator_count;
        int to_move = std::min(queue_count, space);
        
        incubator_count += to_move;
        queue_count -= to_move;
        
        std::cout << to_move << " ovos da fila entraram na incubadora." << std::endl;
        
        if (queue_count == 0) {
            std::cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera." << std::endl;
        } else {
            std::cout << "A fila agora contem " << queue_count << " ovos." << std::endl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int capacity;
    std::cin >> capacity;

    int incubator_count = 0;
    int shiny_count = 0;
    int queue_count = 0;

    std::string command, type_str;

    while (std::cin >> command >> type_str) {
        if (command == "Entraram") {
            if (type_str == "SHINY") {
                incubator_count++;
                shiny_count++;
                std::cout << "Um SHINY entrou na incubadora. Atualmente ha " << incubator_count << " ovos na incubadora." << std::endl;
            } else {
                int amount = std::stoi(type_str);
                int space = capacity - incubator_count;
                
                if (space > 0) {
                    int entered = std::min(amount, space);
                    incubator_count += entered;
                    std::cout << entered << " ovos entraram na incubadora. Atualmente ha " << incubator_count << " ovos na incubadora." << std::endl;
                    
                    int remaining = amount - entered;
                    if (remaining > 0) {
                        queue_count += remaining;
                        std::cout << "Infelizmente a incubadora esta lotada, " << remaining << " ovos foram redirecionadas para a fila." << std::endl;
                        std::cout << "A fila agora contem " << queue_count << " ovos." << std::endl;
                    }
                } else {
                    queue_count += amount;
                    std::cout << "Infelizmente a incubadora esta lotada, " << amount << " ovos foram redirecionadas para a fila." << std::endl;
                    std::cout << "A fila agora contem " << queue_count << " ovos." << std::endl;
                }
            }
        } else if (command == "Sairam") {
            if (type_str == "SHINY") {
                if (shiny_count > 0) {
                    incubator_count--;
                    shiny_count--;
                }
                std::cout << "Um SHINY nasceu. Atualmente ha " << incubator_count << " ovos na incubadora." << std::endl;
                handleQueue(capacity, incubator_count, queue_count);
            } else {
                int amount = std::stoi(type_str);
                incubator_count -= amount;
                std::cout << amount << " ovos chocaram. Atualmente ha " << incubator_count << " ovos na incubadora." << std::endl;
                handleQueue(capacity, incubator_count, queue_count);
            }
        }
        std::cout << std::endl;
    }

    int common_count = incubator_count - shiny_count;

    if (incubator_count == 0) {
        std::cout << "Nao restou nenhum Pokemon na incubadora." << std::endl;
    } else if (common_count == 0) {
        std::cout << "Restaram apenas Pokemon raros na incubadora." << std::endl;
    } else if (shiny_count > 0) {
        std::cout << "Restaram Pokemon raros e comuns na incubadora." << std::endl;
    } else {
        std::cout << "Nao restou nenhum Pokemon raro na incubadora." << std::endl;
    }

    return 0;
}
