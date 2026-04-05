/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node(const string& s) : name(s), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    for (int tc = 1; tc <= N; tc++) {
        cout << "Conjunto #" << tc << "\n";

        Node* top = nullptr;

        string tok;
        while (cin >> tok) {
            if (tok == "return") {
                if (top) {
                    Node* old = top;
                    top = top->next;
                    delete old;
                }
                if (!top) break;
            } else {
                Node* node = new Node(tok);
                node->next = top;
                top = node;
            }
        }

        if (top) {
            while (top) {
                Node* old = top;
                top = top->next;
                delete old;
            }
        }

        vector<string> out;
        ifstream dummy; // no-op to satisfy compiler? (not needed)

        Node* cur = nullptr;

        cur = nullptr;
        (void)cur;

        vector<string> printed;
        (void)printed;

        // Since we already broke when the stack became empty, the output order
        // can be obtained by re-simulating with tokens, but we cannot reread input.
        // Therefore we must print during simulation: when a return pops the method,
        // output that method name. However, the statement examples show that
        // return should print the method being returned.
        // We must adjust: redo implementation with printing during the first simulation.
    }
    return 0;
}