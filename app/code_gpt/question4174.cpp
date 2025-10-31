/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n, n != -1) {
        vector<int> garage(n, -1);
        string command;
        while (cin >> command, command != "o") {
            int k, v, m;
            cin >> k >> v;
            if (command == "i") {
                if (garage[v] != -1) {
                    cout << "Not empty" << endl;
                    bool parked = false;
                    for (int i = (v + 1) % n; i != v; i = (i + 1) % n) {
                        if (garage[i] == -1) {
                            garage[i] = k;
                            parked = true;
                            break;
                        }
                    }
                    if (!parked) cout << "FULL" << endl;
                } else {
                    garage[v] = k;
                }
            } else if (command == "r") {
                if (garage[v] == k) {
                    garage[v] = -1;
                } else {
                    cout << "Not Found" << endl;
                }
            } else if (command == "m") {
                cin >> m;
                if (garage[v] == k) {
                    if (garage[m] == -1) {
                        garage[m] = k;
                        garage[v] = -1;
                    } else {
                        cout << "Not empty" << endl;
                    }
                } else {
                    cout << "Not Found" << endl;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (garage[i] != -1) {
                cout << "Vaga " << i << " -> " << garage[i] << endl;
            }
        }
    }
    return 0;
}
