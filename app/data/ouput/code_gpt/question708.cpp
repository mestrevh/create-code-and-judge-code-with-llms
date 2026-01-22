/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int X;
    while (cin >> X) {
        for (int case_num = 0; case_num < X; ++case_num) {
            int N;
            cin >> N;
            vector<int> C(N);
            for (int i = 0; i < N; ++i) cin >> C[i];

            vector<stack<int>> trucks(N);
            vector<int> weights(N, 0);
            vector<int> load(N, 0);
            vector<int> items_count(N, 0);
            vector<int> warehouse;
            string command;
            cin.ignore();

            while (true) {
                getline(cin, command);
                if (command.empty()) break;

                stringstream ss(command);
                string op;
                ss >> op;

                if (op == "ADD") {
                    int w;
                    ss >> w;
                    warehouse.push_back(w);
                    cout << warehouse.size() << " " << accumulate(warehouse.begin(), warehouse.end(), 0) << endl;
                } else if (op == "LOA") {
                    int i;
                    ss >> i;
                    int total_weight = 0;
                    while (!warehouse.empty() && (total_weight + warehouse.back() <= C[i])) {
                        total_weight += warehouse.back();
                        trucks[i].push(warehouse.back());
                        items_count[i]++;
                        warehouse.pop_back();
                    }
                    cout << i << " " << items_count[i] << endl;
                } else if (op == "DEL") {
                    int i;
                    ss >> i;
                    if (!trucks[i].empty()) {
                        trucks[i].pop();
                        items_count[i]--;
                    }
                    cout << i << " " << items_count[i] << endl;
                } else if (op == "INF") {
                    int i;
                    ss >> i;
                    cout << i << " " << items_count[i] << " " << (items_count[i] > 0 ? accumulate(weights.begin(), weights.end(), 0) : 0) << endl;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
