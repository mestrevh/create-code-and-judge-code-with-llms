/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long Q, P;
    if (!(cin >> Q >> P)) return 0;

    deque<long long> buffer;
    vector<long long> aux;
    aux.reserve(1);

    auto recvK = [&](long long K, long long &id) {
        for (long long i = 0; i < K; i++, id++) {
            if ((long long)buffer.size() < Q) buffer.push_back(id);
            else aux.push_back(id);
        }
    };

    auto moveFromAux = [&]() {
        while (!aux.empty() && (long long)buffer.size() < Q) {
            buffer.push_back(aux.back());
            aux.pop_back();
        }
    };

    vector<vector<long long>> sendOutputs;

    long long opCount = 0;
    string type;
    while (cin >> type) {
        if (type == "RECV") {
            long long K;
            cin >> K;
            static long long nextId = 0;
            recvK(K, nextId);
        } else if (type == "SEND") {
            long long K;
            cin >> K;
            long long take = min(K, (long long)buffer.size());
            vector<long long> out;
            out.reserve(take);
            for (long long i = 0; i < take; i++) {
                out.push_back(buffer.front());
                buffer.pop_front();
            }
            sendOutputs.push_back(move(out));
        } else {
            break;
        }

        opCount++;
        if (opCount == P) {
            moveFromAux();
            opCount = 0;
        }
    }

    for (auto &v : sendOutputs) {
        for (size_t i = 0; i < v.size(); i++) {
            if (i) cout << ' ';
            cout << v[i];
        }
        cout << "\n";
    }

    for (size_t i = 0; i < buffer.size(); i++) {
        if (i) cout << ' ';
        cout << buffer[i];
    }
    cout << "\n";

    if (!aux.empty()) {
        for (long long i = (long long)aux.size() - 1; i >= 0; i--) {
            if (i != (long long)aux.size() - 1) cout << ' ';
            cout << aux[i];
        }
    }
    cout << "\n";

    return 0;
}