/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Patient {
    int pr;
    long long seq;
    string name;
};

struct Cmp {
    bool operator()(const Patient& a, const Patient& b) const {
        if (a.pr != b.pr) return a.pr > b.pr;
        return a.seq > b.seq;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;

        priority_queue<Patient, vector<Patient>, Cmp> pq;
        long long seqGen = 0;

        string cmd;
        cout << "Situação " << tc << "\n\n";
        while (cin >> cmd) {
            if (cmd == "END") break;

            if (cmd == "ARR") {
                string name;
                int pr;
                cin >> name >> pr;
                Patient p{pr, seqGen++, name};

                if ((int)pq.size() < N) {
                    int pos = (int)pq.size() + 1;
                    cout << p.name << ", pos " << pos << "\n";
                    pq.push(p);
                } else {
                    cout << p.name << " foi transferido\n";
                }
            } else if (cmd == "CLL") {
                if (pq.empty()) continue;
                Patient p = pq.top();
                pq.pop();
                cout << p.name << ", atendimento\n";
            }
        }
    }
    return 0;
}