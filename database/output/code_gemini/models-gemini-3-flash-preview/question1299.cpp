/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int orig_p;
    int cur_p;
};

struct ProcessComp {
    bool operator()(const Process& a, const Process& b) const {
        if (a.cur_p != b.cur_p) return a.cur_p > b.cur_p;
        return a.id > b.id;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<long long> N_p(10, 0);
    vector<long long> T_p(10, 0);
    vector<long long> R_p(10, 0);
    vector<long long> U_c(N, 0);
    
    vector<Process> active_process(N);
    set<int> idle_cpus;
    for (int i = 0; i < N; ++i) {
        idle_cpus.insert(i);
    }
    
    priority_queue<Process, vector<Process>, ProcessComp> wait_queue;
    
    string type;
    while (cin >> type && type != "END") {
        if (type == "NEW") {
            int I, P;
            cin >> I >> P;
            N_p[P]++;
            wait_queue.push({I, P, P});
        } else if (type == "STA") {
            int C;
            char S;
            cin >> C >> S;
            Process proc = active_process[C];
            if (S == 'A') {
                proc.cur_p = min(9, proc.cur_p + 1);
                wait_queue.push(proc);
            }
            idle_cpus.insert(C);
        }
        
        while (!wait_queue.empty() && !idle_cpus.empty()) {
            int best_c = *idle_cpus.begin();
            idle_cpus.erase(idle_cpus.begin());
            
            Process next_p = wait_queue.top();
            wait_queue.pop();
            
            active_process[best_c] = next_p;
            int slice_time = 20 - next_p.cur_p;
            
            R_p[next_p.orig_p]++;
            T_p[next_p.orig_p] += slice_time;
            U_c[best_c] += slice_time;
        }
    }
    
    cout << "STATS BY PRIORITY" << "\n\n";
    for (int i = 0; i < 10; ++i) {
        cout << i << ": " << N_p[i] << " " << T_p[i] << " " << R_p[i] << "\n";
    }
    cout << "\n" << "STATS BY CPU" << "\n\n";
    for (int i = 0; i < N; ++i) {
        cout << i << ": " << U_c[i] << "\n";
    }
    
    return 0;
}