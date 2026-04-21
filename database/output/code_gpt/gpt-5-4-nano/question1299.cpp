/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Proc {
    int id;
    int p;
    long long start;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    const int MAXP = 9;

    vector<long long> cntP(MAXP + 1, 0), timeP(MAXP + 1, 0), roundsP(MAXP + 1, 0);
    vector<long long> timeCPU(N, 0);

    using Item = pair<pair<int,int>, Proc*>; 
    struct Cmp {
        bool operator()(const Proc* a, const Proc* b) const {
            if (a->p != b->p) return a->p > b->p;
            return a->id > b->id;
        }
    };
    priority_queue<Proc*, vector<Proc*>, Cmp> q;

    vector<long long> cpuAvailable(N, 0);
    vector<Proc*> cpuProc(N, nullptr);

    string line;
    while (true) {
        if (!getline(cin, line)) break;
        if (line.empty()) continue;
        stringstream ss(line);
        string type;
        ss >> type;
        if (type.empty()) continue;
        if (type == "END") break;

        if (type == "NEW") {
            int I, P;
            ss >> I >> P;
            Proc* pr = new Proc{I, P, 0};
            pr->p = P;
            q.push(pr);
        } else if (type == "STA") {
            int C;
            char S;
            ss >> C >> S;

            Proc* pr = cpuProc[C];
            if (!pr) continue;

            int pOrig = pr->p;
            long long dur = 20LL - pOrig;
            timeP[pOrig] += dur;
            roundsP[pOrig] += 1;
            timeCPU[C] += dur;
            cpuProc[C] = nullptr;

            if (S == 'O') {
                cntP[pOrig] += 1;
                delete pr;
            } else {
                pr->p = min(9, pr->p + 1);
                q.push(pr);
            }

            while (!q.empty()) {
                int targetCpu = -1;
                for (int c = 0; c < N; c++) {
                    if (cpuProc[c] == nullptr) { targetCpu = c; break; }
                }
                if (targetCpu == -1) break;

                Proc* nxt = q.top();
                q.pop();
                cpuProc[targetCpu] = nxt;
                timeCPU[targetCpu] += 0;
            }
        }

        while (true) {
            int freeCpu = -1;
            for (int c = 0; c < N; c++) {
                if (cpuProc[c] == nullptr) { freeCpu = c; break; }
            }
            if (freeCpu == -1 || q.empty()) break;
            Proc* nxt = q.top();
            q.pop();
            cpuProc[freeCpu] = nxt;
        }
    }

    for (int c = 0; c < N; c++) {
        if (cpuProc[c]) delete cpuProc[c];
    }

    cout << "STATS BY PRIORITY\n\n";
    for (int p = 0; p <= 9; p++) {
        cout << p << ": " << cntP[p] << " " << timeP[p] << " " << roundsP[p] << "\n";
    }

    cout << "\nSTATS BY CPU\n\n";
    for (int c = 0; c < N; c++) {
        cout << c << ": " << timeCPU[c] << "\n";
    }

    return 0;
}