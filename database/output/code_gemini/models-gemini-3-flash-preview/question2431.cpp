/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        int N;
        if (!(cin >> N)) break;

        deque<int> reg;
        deque<int> pref;

        cout << "Caso " << t << ":" << "\n";

        for (int i = 0; i < N; ++i) {
            string cmd;
            cin >> cmd;

            if (cmd == "f") {
                int x;
                cin >> x;
                reg.push_back(x);
            } else if (cmd == "p") {
                int x;
                cin >> x;
                pref.push_back(x);
            } else if (cmd == "A") {
                if (!reg.empty()) {
                    reg.pop_front();
                } else if (!pref.empty()) {
                    pref.pop_front();
                }
            } else if (cmd == "B") {
                if (!pref.empty()) {
                    pref.pop_front();
                } else if (!reg.empty()) {
                    reg.pop_front();
                }
            } else if (cmd == "I") {
                int r_front = reg.empty() ? 0 : reg.front();
                int p_front = pref.empty() ? 0 : pref.front();
                cout << r_front << " " << p_front << "\n";
            }
        }
    }

    return 0;
}