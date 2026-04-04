/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct State {
    int side, idx, pos;
    bool operator<(const State& other) const {
        if (side != other.side) return side < other.side;
        if (idx != other.idx) return idx < other.idx;
        return pos < other.pos;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2;
    while (cin >> n1 >> n2) {
        vector<string> A(n1), B(n2);
        for (int i = 0; i < n1; ++i) cin >> A[i];
        for (int i = 0; i < n2; ++i) cin >> B[i];

        queue<State> q;
        set<State> visited;
        bool found = false;

        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (A[i] == B[j]) {
                    found = true;
                    break;
                }
                if (A[i].size() > B[j].size()) {
                    if (A[i].compare(0, B[j].size(), B[j]) == 0) {
                        State s = {0, i, (int)B[j].size()};
                        if (visited.find(s) == visited.end()) {
                            visited.insert(s);
                            q.push(s);
                        }
                    }
                } else {
                    if (B[j].compare(0, A[i].size(), A[i]) == 0) {
                        State s = {1, j, (int)A[i].size()};
                        if (visited.find(s) == visited.end()) {
                            visited.insert(s);
                            q.push(s);
                        }
                    }
                }
            }
            if (found) break;
        }

        if (!found) {
            while (!q.empty()) {
                State curr = q.front();
                q.pop();

                if (curr.side == 0) {
                    int s_len = (int)A[curr.idx].size() - curr.pos;
                    for (int k = 0; k < n2; ++k) {
                        int b_len = (int)B[k].size();
                        if (s_len == b_len) {
                            if (A[curr.idx].compare(curr.pos, string::npos, B[k]) == 0) {
                                found = true;
                                break;
                            }
                        } else if (s_len > b_len) {
                            if (A[curr.idx].compare(curr.pos, b_len, B[k]) == 0) {
                                State next = {0, curr.idx, curr.pos + b_len};
                                if (visited.find(next) == visited.end()) {
                                    visited.insert(next);
                                    q.push(next);
                                }
                            }
                        } else {
                            if (B[k].compare(0, s_len, A[curr.idx], curr.pos, s_len) == 0) {
                                State next = {1, k, s_len};
                                if (visited.find(next) == visited.end()) {
                                    visited.insert(next);
                                    q.push(next);
                                }
                            }
                        }
                    }
                } else {
                    int s_len = (int)B[curr.idx].size() - curr.pos;
                    for (int k = 0; k < n1; ++k) {
                        int a_len = (int)A[k].size();
                        if (s_len == a_len) {
                            if (B[curr.idx].compare(curr.pos, string::npos, A[k]) == 0) {
                                found = true;
                                break;
                            }
                        } else if (s_len > a_len) {
                            if (B[curr.idx].compare(curr.pos, a_len, A[k]) == 0) {
                                State next = {1, curr.idx, curr.pos + a_len};
                                if (visited.find(next) == visited.end()) {
                                    visited.insert(next);
                                    q.push(next);
                                }
                            }
                        } else {
                            if (A[k].compare(0, s_len, B[curr.idx], curr.pos, s_len) == 0) {
                                State next = {0, k, s_len};
                                if (visited.find(next) == visited.end()) {
                                    visited.insert(next);
                                    q.push(next);
                                }
                            }
                        }
                    }
                }
                if (found) break;
            }
        }

        cout << (found ? "S" : "N") << "\n";
    }

    return 0;
}