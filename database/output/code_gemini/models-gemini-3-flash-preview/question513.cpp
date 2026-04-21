/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        int N;
        if (!(cin >> N)) break;

        stack<int> s;
        queue<int> q;
        bool isStack = true;
        bool isQueue = true;

        for (int i = 0; i < N; ++i) {
            int op;
            long long val;
            cin >> op >> val;

            if (op == 1) {
                if (isStack) s.push((int)val);
                if (isQueue) q.push((int)val);
            } else {
                if (isStack) {
                    if (!s.empty() && s.top() == (int)val) {
                        s.pop();
                    } else {
                        isStack = false;
                    }
                }
                if (isQueue) {
                    if (!q.empty() && q.front() == (int)val) {
                        q.pop();
                    } else {
                        isQueue = false;
                    }
                }
            }
        }

        cout << "caso " << t << ": ";
        if (isStack && isQueue) {
            cout << "ambas" << endl;
        } else if (isStack) {
            cout << "pilha" << endl;
        } else if (isQueue) {
            cout << "fila" << endl;
        } else {
            cout << "nenhuma" << endl;
        }
    }

    return 0;
}