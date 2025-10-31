/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    int current_people = 0;
    int captains_count = 0;
    int queue_count = 0;

    std::string action, type_or_count_str;

    while (std::cin >> action >> type_or_count_str) {
        if (action == "Entraram") {
            if (type_or_count_str == "CAPITAO") {
                current_people++;
                captains_count++;
                std::cout << "Um CAPITAO entrou no Perola. Atualmente ha " << current_people << " pessoas na tripulacao.\n";
            } else {
                int num_to_enter = std::stoi(type_or_count_str);
                
                int space_available = std::max(0, N - current_people);
                int can_enter = std::min(num_to_enter, space_available);
                int go_to_queue = num_to_enter - can_enter;

                if (can_enter > 0) {
                    current_people += can_enter;
                    std::cout << can_enter << " pessoas entraram no Perola. Atualmente ha " << current_people << " pessoas na tripulacao.\n";
                }

                if (go_to_queue > 0) {
                    queue_count += go_to_queue;
                    std::cout << "Infelizmente o navio esta lotado, " << go_to_queue << " pessoas foram redirecionadas para a fila.\n";
                    std::cout << "A fila agora contem " << queue_count << " pessoas.\n";
                }
            }
        } else if (action == "Sairam") {
            if (type_or_count_str == "CAPITAO") {
                current_people--;
                captains_count--;
                std::cout << "Um CAPITAO desistiu da aventura. Atualmente ha " << current_people << " pessoas na tripulacao.\n";
            } else {
                int num_to_leave = std::stoi(type_or_count_str);
                current_people -= num_to_leave;
                std::cout << num_to_leave << " pessoas desistiram da aventura. Atualmente ha " << current_people << " pessoas na tripulacao.\n";
            }

            if (queue_count > 0 && current_people < N) {
                int space_available = N - current_people;
                int can_enter_from_queue = std::min(queue_count, space_available);

                if (can_enter_from_queue > 0) {
                    current_people += can_enter_from_queue;
                    queue_count -= can_enter_from_queue;

                    std::cout << can_enter_from_queue << " pessoas da fila entraram no Perola.\n";

                    if (queue_count == 0) {
                        std::cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera.\n";
                    } else {
                        std::cout << "A fila agora contem " << queue_count << " pessoas.\n";
                    }
                }
            }
        }
        std::cout << "\n";
    }

    int regular_crew = current_people - captains_count;
    if (current_people == 0) {
        std::cout << "Cade o Gibbs quando eu preciso dele?\n";
    } else {
        if (captains_count > 0) {
            if (regular_crew <= 0) {
                std::cout << "Sem tripulacao?? E quem voce acha que fara o trabalho sujo??\n";
            } else {
                std::cout << "Preparem-se para a aventura de suas vidas marujos!!!!\n";
            }
        } else {
            std::cout << "Jack? Onde esta o Jack? Como iremos viajar SEM O JACK?\n";
        }
    }

    return 0;
}
