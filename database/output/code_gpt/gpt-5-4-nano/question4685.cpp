/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Task {
    int p;
    string desc;
    long long t;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int opcao;
    vector<Task> tasks;
    long long timer = 0;

    while (cin >> opcao) {
        if (opcao == 0) break;
        if (opcao == 1) {
            string desc;
            int prioridade;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, desc);
            cin >> prioridade;
            tasks.push_back({prioridade, desc, timer++});
        } else if (opcao == 2) {
            sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
                if (a.p != b.p) return a.p < b.p;
                return a.t > b.t;
            });

            cout << "\n";
            for (auto &tk : tasks) {
                cout << tk.p << ". " << tk.desc << "\n";
            }
        }
    }
    return 0;
}