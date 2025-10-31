/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

struct Process {
    int id, priority, timeSpent, rounds;
    Process(int id, int priority) : id(id), priority(priority), timeSpent(0), rounds(0) {}
};

struct cmp {
    bool operator()(const Process &a, const Process &b) {
        if (a.priority == b.priority)
            return a.id > b.id;
        return a.priority > b.priority;
    }
};

int main() {
    int N;
    cin >> N;
    priority_queue<Process, vector<Process>, cmp> pq;
    vector<int> totalProcessed(10, 0), totalTime(10, 0), totalRounds(10, 0);
    vector<int> cpuUsage(N, 0);
    vector<Process> cpu(N, Process(-1, 10)); // -1 indicates free CPU

    string line;
    getline(cin, line); // To consume the newline after N
    while (getline(cin, line) && line != "END") {
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "NEW") {
            int id, priority;
            ss >> id >> priority;
            pq.push(Process(id, priority));
        } else if (command == "STA") {
            int cpuId;
            char status;
            ss >> cpuId >> status;

            if (status == 'O') { // CPU was free
                if (cpu[cpuId].id != -1) {
                    totalProcessed[cpu[cpuId].priority]++;
                    totalTime[cpu[cpuId].priority] += cpuUsage[cpuId];
                    totalRounds[cpu[cpuId].priority]++;
                    cpuUsage[cpuId] = 0; // CPU is now free
                }
            } else if (status == 'A') { // CPU was active
                if (cpu[cpuId].id != -1) {
                    Process proc = cpu[cpuId];
                    totalProcessed[proc.priority]++;
                    totalTime[proc.priority] += cpuUsage[cpuId];
                    totalRounds[proc.priority]++;
                    proc.priority = min(proc.priority + 1, 9);
                    pq.push(proc);
                }
            }

            if (!pq.empty()) {
                Process next = pq.top();
                pq.pop();
                cpu[cpuId] = next;
                cpuUsage[cpuId] = 20 - next.priority;
            }
        }
    }

    cout << "STATS BY PRIORITY\n\n";
    for (int i = 0; i < 10; i++) {
        cout << i << ": " << totalProcessed[i] << " " << totalTime[i] << " " << totalRounds[i] << endl;
    }
    cout << "\nSTATS BY CPU\n\n";
    for (int i = 0; i < N; i++) {
        cout << i << ": " << cpuUsage[i] << endl;
    }
    return 0;
}
