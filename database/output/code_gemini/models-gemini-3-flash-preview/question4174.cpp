/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> garage(N, -1);
    string cmd;

    while (cin >> cmd) {
        if (cmd == "i") {
            int K, v;
            cin >> K >> v;
            if (v < 0 || v >= N) continue;

            int pos = -1;
            if (garage[v] != -1) {
                cout << "Not empty" << endl;
                for (int i = 0; i < N; ++i) {
                    int current = (v + i) % N;
                    if (garage[current] == -1) {
                        pos = current;
                        break;
                    }
                }
            } else {
                pos = v;
            }

            if (pos != -1) {
                garage[pos] = K;
            } else {
                cout << "FULL" << endl;
            }
        } else if (cmd == "r") {
            int K, v;
            cin >> K >> v;
            if (v >= 0 && v < N && garage[v] == K) {
                garage[v] = -1;
            } else {
                cout << "Not Found" << endl;
            }
        } else if (cmd == "m") {
            int K, v, m_target;
            cin >> K >> v >> m_target;
            if (v >= 0 && v < N && garage[v] == K) {
                garage[v] = -1;
                int pos = -1;
                if (garage[m_target] != -1) {
                    cout << "Not empty" << endl;
                    for (int i = 0; i < N; ++i) {
                        int current = (m_target + i) % N;
                        if (garage[current] == -1) {
                            pos = current;
                            break;
                        }
                    }
                } else {
                    pos = m_target;
                }

                if (pos != -1) {
                    garage[pos] = K;
                } else {
                    // This case shouldn't be reached because we just emptied a slot
                    cout << "FULL" << endl;
                }
            } else {
                cout << "Not Found" << endl;
            }
        } else if (cmd == "o") {
            int d1, d2;
            cin >> d1 >> d2;
            break;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (garage[i] != -1) {
            cout << "Vaga " << i << " -> " << garage[i] << endl;
        }
    }

    return 0;
}