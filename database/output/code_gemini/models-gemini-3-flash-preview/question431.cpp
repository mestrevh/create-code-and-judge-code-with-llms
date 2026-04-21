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
    int side; // 0 for Set A ahead, 1 for Set B ahead
    string rem;
    int len;

    bool operator<(const State& other) const {
        if (side != other.side) return side < other.side;
        if (len != other.len) return len < other.len;
        return rem < other.rem;
    }
};

void solve_test_case(int n1, int n2) {
    vector<string> A(n1);
    for (int i = 0; i < n1; ++i) cin >> A[i];
    vector<string> B(n2);
    for (int i = 0; i < n2; ++i) cin >> B[i];

    queue<State> q;
    set<State> visited;
    bool found = false;

    for (const string& a : A) {
        for (const string& b : B) {
            if (a == b) {
                if (a.size() <= 40) {
                    found = true;
                    break;
                }
            } else if (a.size() > b.size()) {
                if (a.substr(0, b.size()) == b && a.size() <= 40) {
                    State s = {0, a.substr(b.size()), (int)a.size()};
                    if (visited.find(s) == visited.end()) {
                        visited.insert(s);
                        q.push(s);
                    }
                }
            } else {
                if (b.substr(0, a.size()) == a && b.size() <= 40) {
                    State s = {1, b.substr(a.size()), (int)b.size()};
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
                for (const string& b : B) {
                    if (curr.rem == b) {
                        found = true;
                        break;
                    }
                    if (curr.rem.size() > b.size()) {
                        if (curr.rem.substr(0, b.size()) == b) {
                            State next = {0, curr.rem.substr(b.size()), curr.len};
                            if (visited.find(next) == visited.end()) {
                                visited.insert(next);
                                q.push(next);
                            }
                        }
                    } else {
                        int nxt_len = curr.len + (b.size() - (int)curr.rem.size());
                        if (nxt_len <= 40 && b.substr(0, curr.rem.size()) == curr.rem) {
                            State next = {1, b.substr(curr.rem.size()), nxt_len};
                            if (visited.find(next) == visited.end()) {
                                visited.insert(next);
                                q.push(next);
                            }
                        }
                    }
                }
            } else {
                for (const string& a : A) {
                    if (curr.rem == a) {
                        found = true;
                        break;
                    }
                    if (curr.rem.size() > a.size()) {
                        if (curr.rem.substr(0, a.size()) == a) {
                            State next = {1, curr.rem.substr(a.size()), curr.len};
                            if (visited.find(next) == visited.end()) {
                                visited.insert(next);
                                q.push(next);
                            }
                        }
                    } else {
                        int nxt_len = curr.len + (a.size() - (int)curr.rem.size());
                        if (nxt_len <= 40 && a.substr(0, curr.rem.size()) == curr.rem) {
                            State next = {0, a.substr(curr.rem.size()), nxt_len};
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

    if (found) cout << "S" << endl;
    else cout << "N" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2;
    while (cin >> n1 >> n2) {
        solve_test_case(n1, n2);
    }

    return 0;
}