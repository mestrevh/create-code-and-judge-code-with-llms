/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <optional>

struct Process {
    int id;
    int priority;
    int original_priority;

    bool operator<(const Process& other) const {
        if (priority != other.priority) {
            return priority > other.priority;
        }
        return id > other.id;
    }
};

int n_cpus;
std::priority_queue<Process> ready_queue;
std::priority_queue<int, std::vector<int>, std::greater<int>> free_cpus;
std::vector<std::optional<Process>> running_on_cpu;

std::vector<long long> stats_n_by_prio(10, 0);
std::vector<long long> stats_t_by_prio(10, 0);
std::vector<long long> stats_r_by_prio(10, 0);
std::vector<long long> stats_u_by_cpu;

void schedule() {
    while (!ready_queue.empty() && !free_cpus.empty()) {
        Process p = ready_queue.top();
        ready_queue.pop();

        int cpu_id = free_cpus.top();
        free_cpus.pop();

        int time_slice = 20 - p.priority;

        stats_r_by_prio[p.original_priority]++;
        stats_t_by_prio[p.original_priority] += time_slice;
        stats_u_by_cpu[cpu_id] += time_slice;

        running_on_cpu[cpu_id] = p;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n_cpus;

    running_on_cpu.resize(n_cpus);
    stats_u_by_cpu.resize(n_cpus, 0);
    for (int i = 0; i < n_cpus; ++i) {
        free_cpus.push(i);
    }

    std::string command;
    while (std::cin >> command && command != "END") {
        if (command == "NEW") {
            int id, priority;
            std::cin >> id >> priority;
            Process p = {id, priority, priority};
            ready_queue.push(p);
            stats_n_by_prio[priority]++;
        } else if (command == "STA") {
            int cpu_id;
            char status;
            std::cin >> cpu_id >> status;

            Process finished_process = running_on_cpu[cpu_id].value();
            running_on_cpu[cpu_id].reset();

            free_cpus.push(cpu_id);

            if (status == 'A') {
                finished_process.priority = std::min(9, finished_process.priority + 1);
                ready_queue.push(finished_process);
            }
        }
        
        schedule();
    }

    std::cout << "STATS BY PRIORITY\n\n";
    for (int p = 0; p <= 9; ++p) {
        std::cout << p << ": " << stats_n_by_prio[p] << " " << stats_t_by_prio[p] << " " << stats_r_by_prio[p] << "\n";
    }
    std::cout << "\nSTATS BY CPU\n\n";
    for (int c = 0; c < n_cpus; ++c) {
        std::cout << c << ": " << stats_u_by_cpu[c] << "\n";
    }

    return 0;
}
