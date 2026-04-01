/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long Q, P;
    if (!(cin >> Q >> P)) return 0;

    deque<long long> buffer;
    vector<long long> auxiliary;
    long long next_id = 0;
    long long op_count = 0;

    string cmd;
    while (cin >> cmd) {
        long long K;
        if (!(cin >> K)) break;

        if (cmd == "RECV") {
            for (long long i = 0; i < K; ++i) {
                if ((long long)buffer.size() < Q) {
                    buffer.push_back(next_id++);
                } else {
                    auxiliary.push_back(next_id++);
                }
            }
        } else if (cmd == "SEND") {
            long long to_send = min(K, (long long)buffer.size());
            for (long long i = 0; i < to_send; ++i) {
                cout << buffer.front() << " ";
                buffer.pop_front();
            }
            cout << "\n";
        }

        op_count++;
        if (op_count % P == 0) {
            while (!auxiliary.empty() && (long long)buffer.size() < Q) {
                buffer.push_back(auxiliary.back());
                auxiliary.pop_back();
            }
        }
    }

    for (size_t i = 0; i < buffer.size(); ++i) {
        cout << buffer[i] << " ";
    }
    cout << "\n";

    for (long long i = (long long)auxiliary.size() - 1; i >= 0; --i) {
        cout << auxiliary[i] << " ";
    }
    cout << "\n";

    return 0;
}