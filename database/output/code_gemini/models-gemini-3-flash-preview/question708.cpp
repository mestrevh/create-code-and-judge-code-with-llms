/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N) {
        vector<long long> capacities(N);
        for (int i = 0; i < N; ++i) {
            cin >> capacities[i];
        }

        string line;
        getline(cin, line); // Consume residual newline and spaces after last capacity

        deque<long long> warehouse;
        long long warehouse_total_weight = 0;
        vector<vector<long long>> trucks_items(N);
        vector<long long> trucks_total_weight(N, 0);

        while (getline(cin, line)) {
            // Handle carriage returns from Windows-style line endings
            if (!line.empty() && line[line.size() - 1] == '\r') {
                line.erase(line.size() - 1);
            }
            
            // A blank line (empty or just whitespace) signals the end of the case
            if (line.empty() || line.find_first_not_of(" \t\n") == string::npos) {
                break;
            }

            stringstream ss(line);
            string cmd;
            if (!(ss >> cmd)) continue;

            if (cmd == "ADD") {
                long long w;
                if (ss >> w) {
                    warehouse.push_back(w);
                    warehouse_total_weight += w;
                    cout << warehouse.size() << " " << warehouse_total_weight << "\n";
                }
            } else if (cmd == "LOA") {
                int i;
                if (ss >> i) {
                    if (i >= 0 && i < N) {
                        while (!warehouse.empty()) {
                            long long next_w = warehouse.front();
                            if (trucks_total_weight[i] + next_w <= capacities[i]) {
                                warehouse.pop_front();
                                warehouse_total_weight -= next_w;
                                trucks_items[i].push_back(next_w);
                                trucks_total_weight[i] += next_w;
                            } else {
                                // According to the rule, stop if the next item doesn't fit
                                break;
                            }
                        }
                        cout << i << " " << (long long)trucks_items[i].size() << "\n";
                    }
                }
            } else if (cmd == "DEL") {
                int i;
                if (ss >> i) {
                    if (i >= 0 && i < N) {
                        if (!trucks_items[i].empty()) {
                            long long last_w = trucks_items[i].back();
                            trucks_items[i].pop_back();
                            trucks_total_weight[i] -= last_w;
                        }
                        cout << i << " " << (long long)trucks_items[i].size() << "\n";
                    }
                }
            } else if (cmd == "INF") {
                int i;
                if (ss >> i) {
                    if (i >= 0 && i < N) {
                        cout << i << " " << (long long)trucks_items[i].size() << " " << trucks_total_weight[i] << "\n";
                    }
                }
            }
        }
        // Print a blank line after each test case
        cout << "\n";
    }

    return 0;
}