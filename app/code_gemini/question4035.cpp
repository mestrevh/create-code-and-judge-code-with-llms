/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long B, E, K, C, F;
    std::cin >> B >> E >> K >> C >> F;

    long long current_table = B;
    std::vector<int> dist_count(F, 0);

    while (current_table <= E) {
        long long remaining_tables_total = 0;
        if (current_table <= E) {
            remaining_tables_total = (E - current_table) / K + 1;
        }

        if (remaining_tables_total == 0) {
            break;
        }

        bool use_egalitarian = (remaining_tables_total < F * C);
        long long base_tables = 0;
        long long extra_tables = 0;
        if (use_egalitarian) {
            if (F > 0) {
                base_tables = remaining_tables_total / F;
                extra_tables = remaining_tables_total % F;
            }
        }

        bool work_done_this_round = false;
        for (int worker = 0; worker < F; ++worker) {
            if (current_table > E) {
                break;
            }

            long long num_to_assign = C;
            if (use_egalitarian) {
                num_to_assign = base_tables;
                if (worker < extra_tables) {
                    num_to_assign++;
                }
            }

            if (num_to_assign == 0) {
                continue;
            }
            
            work_done_this_round = true;
            dist_count[worker]++;

            long long start_table = current_table;
            long long ideal_last_table = start_table + (num_to_assign - 1) * K;
            
            long long last_table = ideal_last_table;
            if (last_table > E) {
                 last_table = start_table + ((E - start_table) / K) * K;
            }
            
            long long actual_assigned = (last_table - start_table) / K + 1;
            
            if (actual_assigned <= 0) {
                 dist_count[worker]--;
                 continue;
            }

            std::cout << "distribution " << dist_count[worker] << " to worker " << worker << ": ";
            if (start_table == last_table) {
                std::cout << start_table << ": ";
            } else {
                std::cout << start_table << "-" << last_table << ": ";
            }

            long long print_table = start_table;
            for (int i = 0; i < actual_assigned; ++i) {
                std::cout << print_table << ", ";
                print_table += K;
            }
            std::cout << "\n";

            current_table = start_table + actual_assigned * K;
        }
        
        if (!work_done_this_round) {
            break;
        }
    }

    return 0;
}
