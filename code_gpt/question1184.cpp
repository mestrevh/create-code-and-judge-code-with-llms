/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int Q, P, seq = 0;
    cin >> Q >> P;

    queue<int> buffer;
    stack<int> aux_memory;
    vector<string> outputs;

    string command;
    while (cin >> command) {
        int K;
        cin >> K;

        if (command == "RECV") {
            for (int i = 0; i < K; ++i) {
                if (buffer.size() < Q) {
                    buffer.push(seq++);
                } else {
                    aux_memory.push(seq++);
                }
            }
        } else if (command == "SEND") {
            vector<int> sent;
            int to_send = min(K, (int)buffer.size());
            for (int i = 0; i < to_send; ++i) {
                sent.push_back(buffer.front());
                buffer.pop();
            }
            outputs.push_back(to_send > 0 ? to_string(sent[0]) : "");
            for (int i = 1; i < to_send; ++i) {
                outputs.back() += " " + to_string(sent[i]);
            }
        }

        if (--P == 0) {
            P = P;  // Reset P back to the original
            while (!aux_memory.empty()) {
                buffer.push(aux_memory.top());
                aux_memory.pop();
            }
        }
    }

    for (const auto &output : outputs) {
        cout << output << endl;
    }

    while (!buffer.empty()) {
        cout << buffer.front() << " ";
        buffer.pop();
    }
    cout << endl;

    while (!aux_memory.empty()) {
        cout << aux_memory.top() << " ";
        aux_memory.pop();
    }
    cout << endl;

    return 0;
}
