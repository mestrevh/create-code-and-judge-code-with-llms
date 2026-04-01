/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

inline char apply_rot13(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (char)((c - 'A' + 13) % 26 + 'A');
    } else if (c >= 'a' && c <= 'z') {
        return (char)((c - 'a' + 13) % 26 + 'a');
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string alphabet;
    if (!(cin >> alphabet)) return 0;

    int pos[256];
    char invA[62];
    for (int i = 0; i < 62; ++i) {
        pos[(unsigned char)alphabet[i]] = i;
        invA[i] = alphabet[i];
    }

    long long n_ops;
    if (!(cin >> n_ops)) return 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    string cmd;
    string msg;
    while (n_ops--) {
        if (!(cin >> cmd)) break;
        if (cmd[1] == 'U') { // PUSH
            if (cin >> msg) {
                for (char c : msg) {
                    pq.push(pos[(unsigned char)c]);
                }
            }
        } else { // POP
            long long m;
            if (cin >> m) {
                for (long long i = 0; i < m; ++i) {
                    int idx = pq.top();
                    pq.pop();
                    cout << apply_rot13(invA[idx]);
                }
                cout << '\n';
            }
        }
    }

    return 0;
}