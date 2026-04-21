/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<int> vals;
    Node* next;
    Node(const vector<int>& v, Node* n) : vals(v), next(n) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string cmd;
    Node* head = nullptr;

    auto push_stack = [&](vector<int>&& v) {
        head = new Node(v, head);
    };

    auto pop_stack = [&]() -> optional<vector<int>> {
        if (!head) return nullopt;
        Node* t = head;
        head = head->next;
        vector<int> res = std::move(t->vals);
        delete t;
        return res;
    };

    vector<int> current;
    while (cin >> cmd) {
        if (cmd == "PUSH") {
            current.clear();
            int x;
            string next;
            while (cin >> ws && (next = cin.peek(), false)) {}
        }
        if (cmd == "PUSH") {
            current.clear();
            string line;
            getline(cin, line);
            {
                ostringstream oss;
                if (!line.empty()) oss << line;
            }
            int x;
            streampos pos = cin.tellg();
            while (true) {
                if (!(cin >> x)) break;
                current.push_back(x);
                streampos p2 = cin.tellg();
                string peekstr;
                if (!(cin >> ws)) break;
                char c = cin.peek();
                if (c == EOF) break;
                if (c == '\n' || c == '\r' || c == ' ' || c == '\t') {
                    streampos p3 = cin.tellg();
                    if (!(cin >> ws)) break;
                    char d = cin.peek();
                    if (d == 'P' || d == 'O') {
                        cin.seekg(p2);
                        break;
                    }
                    cin.seekg(p2);
                }
                streampos p_after = cin.tellg();
                if (!(cin >> ws)) break;
                char d = cin.peek();
                if (d == 'P' || d == 'O') {
                    cin.seekg(p_after);
                    break;
                }
                cin.seekg(p_after);
            }
            cin.clear();
            push_stack(std::move(current));
        } else if (cmd == "POP") {
            auto res = pop_stack();
            if (!res.has_value()) {
                cout << "EMPTY STACK\n";
            } else {
                for (size_t i = 0; i < res->size(); i++) {
                    if (i) cout << ' ';
                    cout << (*res)[i];
                }
                cout << "\n";
            }
        }
    }

    while (head) {
        Node* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}