/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;

        stack<int> s;
        queue<int> q;
        bool isStack = true, isQueue = true;

        for (int i = 0; i < N; ++i) {
            int op, x;
            cin >> op;
            if (op == 1) {
                cin >> x;
                if (isStack) s.push(x);
                if (isQueue) q.push(x);
            } else {
                cin >> x;
                if (isStack) {
                    if (s.empty() || s.top() != x) isStack = false;
                    else s.pop();
                }
                if (isQueue) {
                    if (q.empty() || q.front() != x) isQueue = false;
                    else q.pop();
                }
            }
        }

        string result;
        if (isStack && isQueue) result = "ambas";
        else if (isStack) result = "pilha";
        else if (isQueue) result = "fila";
        else result = "nenhuma";

        cout << "caso " << t << ": " << result << endl;
    }
    return 0;
}
